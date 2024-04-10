#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;

const int MOD = 1000000007;

int silnia[1000006], rev_silnia[1000006];

int dupa(int n, int k) {
    return ((silnia[n + k - 1] * rev_silnia[k - 1]) % MOD * rev_silnia[n]) % MOD;
}

int dupsko(int m, int k) {
    if (m < k) return 0;
    return dupa(m - k, k);
}

int qpot(int a, int b) {
    int res = 1;
    while(b) {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

void jebaj() {

    silnia[0] = 1;
    FOR(i, 1, 1000002) silnia[i] = (silnia[i - 1] * i) % MOD;
    rev_silnia[1000002] = qpot(silnia[1000002], MOD - 2);
    FORD(i, 1000001, 0) rev_silnia[i] = (rev_silnia[i + 1] * (i + 1)) % MOD;

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int res = 0;
    VI pot(n + 1);
    pot[0] = 1;
    FOR(i, 1, n) pot[i] = (pot[i - 1] * m) % MOD;

    for (int ile = 0; ile <= n - 2; ile++) {
        int tmp = 1;
        tmp *= pot[n - ile - 2];
        tmp %= MOD;
        tmp *= rev_silnia[n - 2 - ile];
        tmp %= MOD;
        tmp *= dupsko(m, ile + 1);
        tmp %= MOD;
        if (ile + 2 != n) {
            tmp = (tmp * (ile + 2)) % MOD;
            tmp = (tmp * qpot(n, n - (ile + 2) - 1)) % MOD;
        }
        res += tmp;
    }
    res %= MOD;
    res *= silnia[n - 2];
    res %= MOD;
    cout << res << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}