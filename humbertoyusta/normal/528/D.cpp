#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Pragma, Optimization flags
#define db(x) cerr << #x << ": " << (x) << '\n';
#define f first
#define s second
typedef long double ld;
typedef long long ll;
/// Constraints----------------------------------------------
const int maxn = 500010;
const int mod2 = 1000000007;
const int mod = 998244353;
const ld eps = 1e-9;
/// Quick Functions------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return 1ll * qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return 1ll * pwur * pwur % mod;
}
mt19937_64 random_(time(0));
int rng (int a, int b){
    return uniform_int_distribution<int>(a,b)(random_);
}
/// Code-----------------------------------------------------

namespace fft
{
    #define REP(i,n) for(int i = 0; i < int(n); ++i)
    /* FFT by Errichto / Warsaw U
    Precision error max_ans/1e15 (2.5e18) for (long) doubles.
    So integer rounding works for doubles with answers 0.5*1e15,
    e.g. for sizes 2^20 and RANDOM positive integers up to 45k.
    If there are many small vectors, uncomment "BRUTE FORCE".*/
    typedef double ld; // 'long double' is 2.2 times slower
    struct C {
        ld real, imag;
        C operator * (const C & he) const {
            return C{real * he.real - imag * he.imag,
                    real * he.imag + imag * he.real};
        }
        void operator += (const C & he) {
            real += he.real; imag += he.imag;
        }
    };
    void dft(vector<C> & a, bool rev) {
        const int n = a.size();
        for(int i = 1, k = 0; i < n; ++i) {
            for(int bit = (n >> 1); (k ^= bit) < bit; bit >>= 1);;;
            if(i < k) swap(a[i], a[k]);
        }
        for(int len = 1, who = 0; len < n; (len <<= 1), ++who) {
            static vector<C> t[30];
            vector<C> & om = t[who];
            if(om.empty()) {
                om.resize(len);
                const ld ang = 2 * acosl(0) / len;
                REP(i, len) om[i] = (i&1) || !who ?
                        C{cos(i*ang), sin(i*ang)} : t[who-1][i>>1];
            }
            for(int i = 0; i < n; i += 2 * len)
                REP(k, len) {
                     const C x = a[i+k], y = a[i+k+len]
                            * C{om[k].real, om[k].imag * (rev ? -1 : 1)};
                    a[i+k] += y;
                    a[i+k+len] = C{x.real - y.real, x.imag - y.imag};
                }
        }
        if(rev) REP(i, n) a[i].real /= n;
    }
    template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b, bool split = false) {
        if(a.empty() || b.empty()) return {};
        int n = a.size() + b.size();
        vector<T> ans(n - 1);
        /* if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
            REP(i, a.size()) REP(j, b.size()) ans[i+j] += a[i]*b[j];
            return ans;
        } */
        while(n&(n-1)) ++n;
        // CF/blog/entry/48417
        auto speed = [&](const vector<C> & w, int i, int k) {
            int j = i ? n - i : 0, r = k ? -1 : 1;
            return C{w[i].real + w[j].real * r, w[i].imag
                    - w[j].imag * r} * (k ? C{0, -0.5} : C{0.5, 0});
        };
        if(!split) { // standard fast version
            vector<C> in(n), done(n);
            REP(i, a.size()) in[i].real = a[i];
            REP(i, b.size()) in[i].imag = b[i];
            dft(in, false);
            REP(i, n) done[i] = speed(in, i, 0) * speed(in, i, 1);
            dft(done, true);
            REP(i, ans.size()) ans[i] = is_integral<T>::value ?
                    llround(done[i].real) : done[i].real;
        }
        else { // Split big INTEGERS into pairs a1*M+a2,
            const T M = 31600; // where M = sqrt(max_absvalue).
            vector<C> t[2]; // This version is 2.2-2.5 times slower.
            REP(x, 2) {
                t[x].resize(n);
                auto & in = x ? b : a;
                REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
                dft(t[x], false);
            }
            T mul = 1;
            for(int s = 0; s < 3; ++s, mul *= M) {
                vector<C> prod(n);
                REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
                    prod[i] += speed(t[0], i, x) * speed(t[1], i, y);
                dft(prod, true);
                REP(i, ans.size()) ans[i]+= llround(prod[i].real)*mul;
                // in case of modulo: ans[i] = (ans[i] + llround(prod[i].real)%MOD*mul) % MOD;
            }
        }
        return ans;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, m, k;

    cin >> n >> m >> k;

    string s, t;
    cin >> s >> t;

    vector<int> a(n), b(m);

    for(int i=0; i<n; i++){
        if( s[i] == 'A' ) a[i] = 1;
        if( s[i] == 'G' ) a[i] = 2;
        if( s[i] == 'T' ) a[i] = 3;
        if( s[i] == 'C' ) a[i] = 4;
    }

    for(int i=0; i<m; i++){
        if( t[i] == 'A' ) b[i] = 1;
        if( t[i] == 'G' ) b[i] = 2;
        if( t[i] == 'T' ) b[i] = 3;
        if( t[i] == 'C' ) b[i] = 4;
    }

    vector<int> matches(n);
    for(int i=1; i<=4; i++){

        vector<int> c(n), d(m);

        for(int j=0; j<n; j++){
            if( a[j] == i ){
                c[max(0,j-k)] ++;
                if( j + k + 1 < n )
                    c[j+k+1] --;
            }
        }
        for(int j=0; j<n; j++)
            if( j )
                c[j] += c[j-1];
        for(int j=0; j<n; j++)
            c[j] = ( c[j] > 0 );

        for(int j=0; j<m; j++)
            d[j] = ( b[j] == i );

        reverse(d.begin(),d.end());

        vector<int> tmatches = fft::multiply(c,d,0);
        for(int j=(int)d.size()-1; j<(int)d.size()-1+n-m+1; j++)
            matches[j-(int)d.size()+1] += tmatches[j];
    }

    int ans = 0;
    for(int i=0; i<n-m+1; i++)
        ans += ( matches[i] == m );
    cout << ans << '\n';

    return 0;
}