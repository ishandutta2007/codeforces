#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
/* 
 * Fast Fourier transform for x86-64 AVX (C)
 * 
 * Copyright (c) 2017 Project Nayuki. (MIT License)
 * https://www.nayuki.io/page/fast-fourier-transform-in-x86-assembly
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * - The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 * - The Software is provided "as is", without warranty of any kind, express or
 *   implied, including but not limited to the warranties of merchantability,
 *   fitness for a particular purpose and noninfringement. In no event shall the
 *   authors or copyright holders be liable for any claim, damages or other
 *   liability, whether in an action of contract, tort or otherwise, arising from,
 *   out of or in connection with the Software or the use or other dealings in the
 *   Software.
 */

#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
double PI = 2.0*acos(0.0);

// Private data structure
struct FftTables {
    int n;
    int *bit_reversed;
    double *trig_tables;
};


// Private function prototypes
static double accurate_sine(int i, int n);
static int floor_log2(int n);
static int reverse_bits(int x, int n);


/*---- Function implementations ----*/

// Returns a pointer to an opaque structure of FFT tables. n must be a power of 2 and n >= 4.
void *fft_init(size_t n) {
    // Check size argument
    if (n < 4 || n > UINT64_MAX || (n & (n - 1)) != 0)
        return NULL;  // Error: Size is too small or is not a power of 2
    if (n - 4 > SIZE_MAX / sizeof(double) / 2 || n > SIZE_MAX / sizeof(size_t))
        return NULL;  // Error: Size is too large, which makes memory allocation impossible
    
    // Allocate structure
    struct FftTables *tables = new FftTables();
    if (tables == NULL)
        return NULL;
    tables->n = n;
    
    // Allocate arrays
    tables->bit_reversed = new int[n];
    tables->trig_tables = new double[2 * n + 1];
    if (tables->bit_reversed == NULL || tables->trig_tables == NULL) {
        free(tables->bit_reversed);
        free(tables->trig_tables);
        free(tables);
        return NULL;
    }
    
    // Precompute bit reversal table
    int levels = floor_log2(n);
    for (int i = 0; i < n; i++)
        tables->bit_reversed[i] = reverse_bits(i, levels);
    // Precompute the packed trigonometric table for each FFT internal level
    int k = 0;
    for (int size = 8; size <= n; size *= 2) {
        for (int i = 0; i < size / 2; i += 4) {
            for (int j = 0; j < 4; j++, k++){
                tables->trig_tables[k] = accurate_sine(i + j + size / 4, size);  // Cosine
            }
            for (int j = 0; j < 4; j++, k++){
                tables->trig_tables[k] = accurate_sine(i + j, size);  // Sine
            }
        }
        if (size == n)
            break;
    }
    return tables;
}


// Deallocates the given structure of FFT tables.
void fft_destroy(void *tables) {
    if (tables == NULL)
        return;
    struct FftTables *tbl = (struct FftTables *)tables;
    free(tbl->bit_reversed);
    free(tbl->trig_tables);
    memset(tbl, 0, sizeof(struct FftTables));  // Prevent accidental memory reuse
    free(tbl);
}


// Returns sin(2 * pi * i / n), for n that is a multiple of 4.
static double accurate_sine(int i, int n) {
    if (n % 4 != 0)
        return NAN;
    else {
        int neg = 0;  // Boolean
        // Reduce to full cycle
        i %= n;
        // Reduce to half cycle
        if (i >= n / 2) {
            neg = 1;
            i -= n / 2;
        }
        // Reduce to quarter cycle
        if (i >= n / 4)
            i = n / 2 - i;
        // Reduce to eighth cycle
        double val;
        if (i * 8 < n)
            val = sin(2 * PI * i / n);
        else
            val = cos(2 * PI * (n / 4 - i) / n);
        // Apply sign
        return neg ? -val : val;
    }
}


// Returns the largest i such that 2^i <= n.
static int floor_log2(int n) {
    int result = 0;
    for (; n > 1; n /= 2)
        result++;
    return result;
}


// Returns the bit reversal of the n-bit unsigned integer x.
static int reverse_bits(int x, int n) {
    int result = 0;
    for (int i = 0; i < n; i++, x >>= 1){
        result = (result << 1) | (x & 1);
    }
    return result;
}

// 2^K = max polynomial size
const int K = 19;

double _r[1 << K], _i[1 << K];
// This is a C implementation that models the x86-64 AVX implementation.
void fft_transform(const void *tables) {
    const struct FftTables *tbl = (const struct FftTables *)tables;
    int n = tbl->n;
    // Bit-reversed addressing permutation
    const int *bitreversed = tbl->bit_reversed;
    for (int i = 0; i < n; i++) {
        int j = bitreversed[i];
        if (i < j) {
            double tp0re = _r[i];
            double tp0im = _i[i];
            double tp1re = _r[j];
            double tp1im = _i[j];
            _r[i] = tp1re;
            _i[i] = tp1im;
            _r[j] = tp0re;
            _i[j] = tp0im;
        }
    }
    
    // Size 2 merge (special)
    if (n >= 2) {
        for (int i = 0; i < n; i += 2) {
            double tpre = _r[i];
            double tpim = _i[i];
            _r[i] += _r[i + 1];
            _i[i] += _i[i + 1];
            _r[i + 1] = tpre - _r[i + 1];
            _i[i + 1] = tpim - _i[i + 1];
        }
    }
    
    // Size 4 merge (special)
    if (n >= 4) {
        for (int i = 0; i < n; i += 4) {
            // Even indices
            double tpre, tpim;
            tpre = _r[i];
            tpim = _i[i];
            _r[i] += _r[i + 2];
            _i[i] += _i[i + 2];
            _r[i + 2] = tpre - _r[i + 2];
            _i[i + 2] = tpim - _i[i + 2];
            // Odd indices
            tpre = _r[i + 1];
            tpim = _i[i + 1];
            _r[i + 1] += _i[i + 3];
            _i[i + 1] -= _r[i + 3];
            tpre -= _i[i + 3];
            tpim += _r[i + 3];
            _r[i + 3] = tpre;
            _i[i + 3] = tpim;
        }
    }
    
    // Size 8 and larger merges (general)
    const double *trigtables = tbl->trig_tables;
    for (int size = 8; size <= n; size <<= 1) {
        int halfsize = size >> 1;
        for (int i = 0; i < n; i += size) {
            for (int j = 0, off = 0; j < halfsize; j += 4, off += 8) {
                for (int k = 0; k < 4; k++) {  // To simulate x86 AVX 4-vectors
                    int vi = i + j + k;  // Vector index
                    int ti = off + k;    // Table index
                    double re = _r[vi + halfsize];
                    double im = _i[vi + halfsize];
                    double tpre = re * trigtables[ti] + im * trigtables[ti + 4];
                    double tpim = im * trigtables[ti] - re * trigtables[ti + 4];
                    _r[vi + halfsize] = _r[vi] - tpre;
                    _i[vi + halfsize] = _i[vi] - tpim;
                    _r[vi] += tpre;
                    _i[vi] += tpim;
                }
            }
        }
        if (size == n)
            break;
        trigtables += size;
    }
}



#define ll long long
#define vi vector<int>
#define ld double

struct base{
    ld x,y;
    base(){x=y=0;}
    base(ld _x, ld _y){x = _x,y = _y;}
    base(ld _x){x = _x, y = 0;}
    void operator = (ld _x){x = _x,y = 0;}
    ld real(){return x;}
    ld imag(){return y;}
    base operator + (const base& b){return base(x+b.x,y+b.y);}
    void operator += (const base& b){x+=b.x,y+=b.y;}
    base operator * (const base& b){return base(x*b.x - y*b.y,x*b.y+y*b.x);}
    void operator *= (const base& b){ld p = x*b.x - y*b.y, q = x*b.y+y*b.x; x = p, y = q;}
    void operator /= (ld k){x/=k,y/=k;}
    base operator - (const base& b){return base(x - b.x,y - b.y);}
    void operator -= (const base& b){x -= b.x, y -= b.y;}
    base conj(){ return base(x, -y);}
};


// assumes fft_init() already called
void * tables[K + 1];

void precompute_tables(){
    for(int i = 2; i <= K; i++) tables[i] = fft_init(1 << i);
}

unsigned ll temp[1 << K];
vi naive_mul(vi & a, vi & b){
    int sz = a.size() + b.size() - 1;
    vi c(sz);
    // for(int i = 0; i < sz; i++) temp[i] = 0;
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * (ll) b[j];
    return c;
}

void fft (vector<base> & a, bool invert) {
    int n = a.size();
    for(int i = 0; i < n; i++){
        _r[i] = a[i].x, _i[i] = a[i].y;
    }
    int m = floor_log2(n);
    if(!tables[m]) tables[m] = fft_init(n);
    fft_transform(tables[m]);
    a[0] = base(_r[0], _i[0]);
    for(int i = 1; i < n; i++){
        a[i] = base(_r[invert ? n - i : i], _i[invert ? n - i : i]);
    }
    if (invert) for (int i=0; i<n; ++i) a[i] /= n;
}



void mul(vi & a, vi b) {
    int sza = a.size();
    int szb = b.size();
    int fsz = sza + szb - 1;
    int n = 1;
    while (n < fsz)  n <<= 1;
    vector<base> fa(n);
    
    for(int i = 0; i < sza; i++) fa[i] += base(a[i]);
    for(int i = 0; i < szb; i++) fa[i] += base(0, 1) * base(b[i]);

    fft (fa, false);
     for(int i = 0 ; i <= (n >> 1) ; ++i){
        base p = fa[i] + fa[(n - i) % n].conj();
        base q = fa[i] - fa[(n - i) % n].conj();
        fa[i] = (p * q * base(0, -0.25)) ;
        if(i > 0) fa[(n - i)] = fa[i].conj();
    }
    fft (fa, true);
    a.resize (fsz);
    for(int i = 0;i<fsz;i++)
        a[i] = ( (ll) (fa[i].real() + 0.5));
}


const int N = 200005;
char S[N], T[N];
int cnt[N], pref[4][N], b[N];
vector<int> v1, v2;
int val(char c){ if(c == 'A') return 1; if(c == 'T') return 0; if(c == 'C') return 2; if(c == 'G') return 3;}
int main(){
    int n, m, k;
    sd(n); sd(m); sd(k);
    v1.resize(n + 1); v2.resize(n + 1);
    scanf("%s ", S);
    scanf("%s", T);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++) pref[j][i] = pref[j][i - 1];
        pref[val(S[i - 1])][i] ++; 
    }
    for(int j = 0; j < 4; j++){
        v1.clear();
        v1.resize(n + 1);
        for(int i = 0; i < m; i++) v1[i] = (val(T[i]) == j);
        for(int i = 1; i <= n; i++){
            int lo = i - k, hi = i + k;
            v2[n + 1 - i] = (pref[j][min(hi, n)] > pref[j][max(0, lo - 1)]);
        }
        mul(v1, v2);
        for(int i = 1; i <= n; i++) cnt[i] += v1[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(cnt[i] == m)ans++;
    cout << ans << endl;
}