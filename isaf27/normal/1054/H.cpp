// 2018, Sayutin Dmitry.

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

#define pb push_back
#define eb emplace_back

const int mod = 490019;
const int phi = mod - 1; // = 2 * 491 * 499

int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}

int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

int fastpow(int a, int n, int md, int r = 1) {
    while (n) {
        if (n % 2)
            r = (int64_t(r) * a) % md;
        
        a = (int64_t(a) * a) % md;
        n /= 2;
    }

    return r;
}

const int LOG_N = 10;
const int FFT_N = (1 << LOG_N);

struct complex {
    complex(): x(0), y(0) {}
    complex(double x, double y = 0): x(x), y(y) {}

    complex operator+(complex other) {return complex(x + other.x, y + other.y);}
    complex operator+=(complex other) {x += other.x; y += other.y; return *this;}
    complex operator-(complex other) {return complex(x - other.x, y - other.y);}

    complex operator*(complex other) {return complex(x * other.x - y * other.y, x * other.y + y * other.x);}

    complex operator/=(int val) {x /= val; y /= val; return *this;}
    
    inline double real() {return x;}
    inline double imag() {return y;}
    
    double x;
    double y;
};

complex w[FFT_N];
int rev[FFT_N];

#if 1

void precalc() {
    // /2 [0;1) -> [1;1]
    // /4 [0;2) -> [2;3]
    // /8 [0;4) -> [4;7]
    // ..
    // /FFT_N [0;FFT_N / 2) -> [FFT_N / 2; FFT_N - 1]
    
    double pi = acos(-1);

    for (int i = 0; i != FFT_N / 2; ++i)
        w[FFT_N / 2 + i] = complex(cos(2.0 * pi * double(i) / FFT_N), sin(2.0 * pi * double(i) / FFT_N));

    for (int n = FFT_N / 2; n >= 2; n /= 2)
        for (int i = 0; i != n / 2; ++i)
            w[n / 2 + i] = w[n + 2 * i];

    rev[0] = 0;
    int last = 0;
    for (int i = 1; i != FFT_N; ++i) {
        if (i == (2 << last))
            ++last;

        rev[i] = rev[i ^ (1 << last)] | (1 << (LOG_N - 1 - last));
    }
}

void fft(complex* a) {
    for (int i = 0; i < FFT_N; ++i)
        if (i < rev[i])
            std::swap(a[i], a[rev[i]]);

    for (int n = 1; n < FFT_N; n = n << 1)
        for (int start = 0; start < FFT_N; start += (n << 1))
            for (int off = 0; off < n; ++off) {
                complex x = a[start + off];
                complex y = a[start + off + n] * w[n + off];

                a[start + off]     = x + y;
                a[start + off + n] = x - y;
            }
}

#else

void precalc() {
    double pi = acos(-1);
    for (int i = 0; i != FFT_N; ++i)
        w[i] = complex(cos(2.0 * pi * double(i) / FFT_N), sin(2.0 * pi * double(i) / FFT_N));

    rev[0] = 0;
    int last = 0;
    for (int i = 1; i != FFT_N; ++i) {
        if (i == (2 << last))
            ++last;

        rev[i] = rev[i ^ (1 << last)] | (1 << (LOG_N - 1 - last));
    }
}


void fft(complex* a) {
    for (int i = 0; i < FFT_N; ++i)
        if (i < rev[i])
            std::swap(a[i], a[rev[i]]);

    for (int lvl = 0; lvl < LOG_N; ++lvl)
        for (int start = 0; start < FFT_N; start += (2 << lvl))
            for (int off = 0; off < (1 << lvl); ++off) {
                complex x = a[start + off];
                complex y = a[start + off + (1 << lvl)] * w[off << (LOG_N - 1 - lvl)];

                a[start + off + (0 << lvl)] = x + y;
                a[start + off + (1 << lvl)] = x - y;
            }
}

#endif 


void inv_fft(complex* a) {
    fft(a);
    std::reverse(a + 1, a + FFT_N);
    for (int i = 0; i != FFT_N; ++i)
        a[i] /= FFT_N;
}

int inverse(int a, int md) {
    return fastpow(a % md, md - 2, md);
}

// [0; phi) -> [0; 2) x [0; 491) x [0; 499)
tuple<int, int, int> chinese_it(int num) {
    return make_tuple(num % 2, num % 491, num % 499);
}

void chinese_it(int num, int& a, int& b, int& c) {
    a = num % 2;
    b = num % 491;
    c = num % 499;
}

// [0; 2) x [0; 491) x [0; 499) -> [0; phi)
int un_chinese_it(int a, int b, int c) {
    static int X = (int64_t(491 * 499) * inverse(491 * 499, 2)) % phi;
    static int Y = (int64_t(2 * 499) * inverse(2 * 499, 491)) % phi;
    static int Z = (int64_t(2 * 491) * inverse(2 * 491, 499)) % phi;

    return (a * X + b * Y + c * Z) % phi;
}

int primitive491 = 7;
int primitive499 = 7;

int pr_pows491[491];
int pr_pows499[499];

int log491[491];
int log499[499];

#ifndef LOCAL
#define STAMP(msg) {fprintf(stderr, "%0.2lf: %s\n", clock() / double(CLOCKS_PER_SEC), msg);}
#else
#define STAMP(msg)
#endif

int main() {
    STAMP("start");
    
    // code here
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);

    vector<int> a(n);
    vector<int> b(m);

    for (int& elem: a)
        scanf("%d", &elem);
    for (int& elem: b)
        scanf("%d", &elem);
    
    vector<int> pows(phi);
    pows[0] = 1;
    for (int i = 1; i != phi; ++i)
        pows[i] = mult(pows[i - 1], c);

    // handle all "% 491 == 0" and "% 499 == 0"

    vector<int> spec;
    for (int i = 0; i < max(n, m); i += 491)
        spec.push_back(i);
    for (int i = 0; i < max(n, m); i += 499)
        spec.push_back(i);

    std::sort(ALL(spec));
    spec.resize(std::unique(ALL(spec)) - spec.begin());
    
    int res = 0;

    STAMP("before");

    fprintf(stderr, "spec: %d\n", SZ(spec));

    for (int j = 0; j != m; ++j) {
        int j3 = (j * int64_t(j) * j) % phi;

        int64_t sum = 0;
        
        for (int i: spec) {
            if (i > n)
                break;

            int i2 = (i * int64_t(i)) % phi;
            
            int k = a[i] * b[j];
    
            sum += int64_t(k) * pows[(i2 * int64_t(j3)) % phi];
        }

        res = (res + sum) % mod;
    }

    STAMP("stage1 done");

    for (int j: spec) {
        int j3 = (j * int64_t(j) * j) % phi;

        int64_t sum = 0;
        for (int i = 0; i != n; ++i) {
            int i2 = (i * int64_t(i)) % phi;
            if (j > m)
                break;
            
            int k = (a[i] * b[j]);
            
            sum += int64_t(k) * pows[(i2 * int64_t(j3)) % phi];
        }

        res = (res + sum) % mod;
    }

    STAMP("stage2 done");
    
    for (int i: spec)
        for (int j: spec) {
            if (i > n or j > m)
                break;

            int k = (a[i] * b[j]);
            
            int i2 = (i * int64_t(i)) % phi;

            int j3 = (j * int64_t(j) * j) % phi;
            
            res = (res - int64_t(k) * pows[(i2 * int64_t(j3)) % phi]) % mod;

            if (res < 0)
                res += mod;
        }

    STAMP("stage3 done");
    
    pr_pows491[0] = 1;
    for (int i = 1; i < 491; ++i)
        pr_pows491[i] = (pr_pows491[i - 1] * primitive491) % 491;

    for (int i = 0; i < 490; ++i)
        log491[pr_pows491[i]] = i;
    
    pr_pows499[0] = 1;
    for (int i = 1; i < 499; ++i)
        pr_pows499[i] = (pr_pows499[i - 1] * primitive499) % 499;

    for (int i = 0; i < 498; ++i)
        log499[pr_pows499[i]] = i;
    
    STAMP("before ffts");

    complex arr[2][1024][1024];

    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 1024; ++j)
            for (int k = 0; k != 1024; ++k)
                arr[i][j][k] = 0.0;

    for (int i = 0; i != n; ++i) {
        int x, y, z;
        chinese_it(i, x, y, z);

        if (y == 0 or z == 0)
            continue;

        y = (2 * log491[y]) % 490;
        z = (2 * log499[z]) % 498;

        arr[x][y][z] += complex(a[i], 0);
        if (x == 1)
            arr[0][y][z] += complex(a[i], 0);
    }

    for (int i = 0; i != m; ++i) {
        int x, y, z;
        chinese_it(i, x, y, z);

        if (y == 0 or z == 0)
            continue;

        y = (3 * log491[y]) % 490;
        z = (3 * log499[z]) % 498;

        arr[x][y][z] += complex(0, b[i]);
        if (x == 1)
            arr[0][y][z] += complex(0, b[i]);
    }

    STAMP("prepare done");
    
    precalc();

    STAMP("precalc done");

    for (int i = 0; i != 2; ++i) {
        for (int j = 0; j != 1024; ++j)
            fft(arr[i][j]);

        complex tmp[1024];
        for (int k = 0; k != 1024; ++k) {
            for (int j = 0; j != 1024; ++j)
                tmp[j] = arr[i][j][k];

            fft(tmp);

            for (int j = 0; j != 1024; ++j)
                arr[i][j][k] = tmp[j];
        }
    }

    STAMP("fft1");
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 1024; ++j)
            for (int k = 0; k != 1024; ++k)
                arr[i][j][k] = arr[i][j][k] * arr[i][j][k];

    STAMP("fft+fft");

    for (int i = 0; i != 2; ++i) {
        for (int j = 0; j != 1024; ++j)
            inv_fft(arr[i][j]);

        complex tmp[1024];
        for (int k = 0; k != 1024; ++k) {
            for (int j = 0; j != 1024; ++j)
                tmp[j] = arr[i][j][k];

            inv_fft(tmp);

            for (int j = 0; j != 1024; ++j)
                arr[i][j][k] = tmp[j];
        }
    }        
    
    STAMP("fft2");
    
    // cout << "====\n";
    
    for (int i = 0; i != 2; ++i)
        for (int j = 0; j != 1024; ++j)
            for (int k = 0; k != 1024; ++k) {
                int64_t val = round(arr[i][j][k].imag() / 2.0);

                if (i == 0)
                    val -= round(arr[1][j][k].imag() / 2.0);
                
                val %= mod;

                int ip = i;
                int jp = pr_pows491[j % 490];
                int kp = pr_pows499[k % 498];
        
                res = (res + val * pows[un_chinese_it(ip, jp, kp)]) % mod;
            }

    STAMP("fi");

    printf("%d\n", res);

    return 0;
}