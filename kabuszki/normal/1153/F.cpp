#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

const int M = 4444;
const int MOD = 998244353;

VI fac(M), inv_fac(M), pot2(M);

int qpot(int a, int b) {
    int res = 1;
    while(b) {
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int inv(int a) {
    return qpot(a, MOD - 2);
}

int prepro() {
    fac[0] = 1;
    for (int i = 1; i < M; i++) fac[i] = (fac[i - 1] * i) % MOD;
    inv_fac[M - 1] = inv(fac[M - 1]);
    for (int i = M - 2; i >= 0; i--) inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % MOD;
    pot2[0] = 1;
    for (int i = 1; i < M; i++) pot2[i] = (pot2[i - 1] * 2) % MOD;
}

int licz(int a, int n, int k) {
    int res = 0, b = 2 * n - a;
    for (int i = k; i <= a; i++) {
        if ((a - i) % 2 == 0 && b >= i) {
            int tmp = pot2[i];
            tmp = (tmp * inv_fac[i]) % MOD;
            //tmp = (tmp * inv_fac[i]) % MOD;
            tmp = (tmp * inv_fac[(a - i) / 2]) % MOD;
            tmp = (tmp * inv_fac[(b - i) / 2]) % MOD;
            res = res + tmp;
        }
    }
    res %= MOD;
    res = (res * fac[a]) % MOD;
    res = (res * fac[b]) % MOD;
    res = (res * fac[n]) % MOD;
    res = (res * inv_fac[2 * n]) % MOD;
   // cerr << a << " " << n << " " << k << " " << res << "\n";
    return res;
}

void jebaj() {
    int n, k, l;
    cin >> n >> k >> l;
    int res = 0;
    for (int a = 1; a < 2 * n; a++) {
        res = res + licz(a, n, k);
        res %= MOD;
    }
    res = ((res * l) % MOD * inv(2 * n + 1)) % MOD;
    cout << res << "\n";

}

#undef int

int main() {

    #define int long long
    prepro();
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}