#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long double rl;
namespace FFT {
    struct cpl { rl a, b; cpl(rl a_=0, rl b_=0) : a(a_), b(b_) {}};
    cpl mul(cpl x, cpl y) { return {x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a}; }
    cpl add(cpl x, cpl y) { return {x.a+y.a,x.b+y.b}; }
    cpl sub(cpl x, cpl y) { return {x.a-y.a,x.b-y.b}; }

    const static int N = 1<<20;
    const static rl PI = acos(rl(-1));
    cpl wpw[N];

    void fft(vector<cpl> &a, bool inv) {
        int n = sz(a);
        assert(1 <= n && n <= N);
        assert((n & (n-1)) == 0);
        for (int i = 1, j = 0, b; i < n; i++) {
            for (b = n>>1; j >= b; b >>= 1) j -= b;
            j += b;
            if (i < j) swap(a[i],a[j]);
        }
        for (int b = 2; b <= n; b <<= 1) {
            rl ang = 2 * PI / b * (inv ? -1 : 1);
            cpl w = {cos(ang),sin(ang)};
            wpw[0] = {1,0};
            FO(i,1,b/2) wpw[i] = mul(w,wpw[i-1]);
            for (int i = 0; i < n; i += b) FO(j,0,b/2) {
                cpl u = a[i+j], v = mul(wpw[j], a[i+j+b/2]);
                a[i+j] = add(u,v);
                a[i+j+b/2] = sub(u,v);
            }
        }
        if (inv) FO(i,0,n) a[i].a /= n, a[i].b /= n;
    }

    vector<rl> rmul(const vector<rl> &a, const vector<rl> &b) {
        int n = 1;
        while (n < sz(a)+sz(b)) n <<= 1;
        n <<= 1;
        vector<cpl> A(n), B(n);
        FO(i,0,sz(a)) A[i] = {a[i],0};
        FO(i,0,sz(b)) B[i] = {b[i],0};
        fft(A,false); fft(B,false);
        FO(i,0,n) A[i] = mul(A[i],B[i]);
        fft(A,true);
        vector<rl> c(n);
        FO(i,0,n) c[i] = A[i].a;
        return c;
    }

    vector<long long> imul(const vector<int> &a, const vector<int> &b) {
        vector<rl> A(a.begin(),a.end()), B(b.begin(),b.end());
        vector<rl> C = rmul(A,B);
        vector<long long> c(sz(C));
        FO(i,0,sz(c)) c[i] = roundl(C[i]);
        return c;
    }

    vector<int> imulmod(const vector<int> &a, const vector<int> &b, int mod=1000000007) {
        int B = sqrt(mod);
        int n = sz(a), m = sz(b);
        vector<int> a0(n), a1(n), b0(m), b1(m);
        FO(i,0,n) { a0[i] = a[i]%B; a1[i] = a[i]/B; }
        FO(i,0,m) { b0[i] = b[i]%B; b1[i] = b[i]/B; }

        vector<long long> z0 = imul(a0,b0), z1 = imul(a0,b1), Z1 = imul(a1,b0), z2 = imul(a1,b1);
        FO(i,0,sz(z0)) {
            z0[i] += (z1[i]+Z1[i])%mod * B;
            z0[i] += z2[i]%mod * B * B;
            z0[i] %= mod;
        }
        vector<int> r(sz(z0));
        FO(i,0,sz(r)) r[i] = z0[i];

        return r;
    }
};

#define MOD 1000000007

typedef long long ll;
ll f[30005], vf[30005];
int n, k;

ll pw(ll a, ll b) {
    ll r = 1;
    for (;b;b>>=1,a=(a*a)%MOD) if (b&1) r=(r*a)%MOD;
    return r;
}

vector<int> mul(vector<int> a, int la, vector<int> b, int lb) {
    FO(i,0,k+1) a[i] = a[i]*vf[i]%MOD*pw(2,i*lb)%MOD;
    FO(i,0,k+1) b[i] = (b[i]*vf[i])%MOD;
    vector<int> r = FFT::imulmod(a,b);
    r.resize(k+1);
    FO(i,0,k+1) r[i] = (r[i]*f[i])%MOD;
    return r;
}

vector<int> pw(vector<int> a, int b) {
    vector<int> r(k+1); r[0] = 1; int la = 1, lr = 0;
    for (;b;b>>=1,a=mul(a,la,a,la),la+=la) if (b&1) r=mul(r,lr,a,la), lr += la;
    return r;
}

int main() {
    long long nn;
    scanf("%lld%d", &nn, &k);
    if (nn > k) {
        printf("0\n");
        return 0;
    }
    n = nn;

    f[0] = vf[0] = 1;
    FO(i,1,k+1) {
        f[i] = i*f[i-1]%MOD;
        vf[i] = pw(f[i],MOD-2);
    }
    vector<int> r(k+1);
    FO(i,1,k+1) r[i] = 1;
    r = pw(r,n);
    long long res = 0;
    FO(i,0,k+1) res += r[i] * f[k] % MOD * vf[i] % MOD * vf[k-i] % MOD;
    printf("%lld\n", res%MOD);
}