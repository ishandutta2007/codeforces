#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
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

int MOD = 1000000007;

int dp[50][50][50];

void prepro() {
    REP(s, 50) REP(i, 16) REP(j, 16) {
        int k = s - i - j;
        if (k < 0) continue;
        if (j == 0 && k == 0) dp[i][j][k] = (i == 0);
        else {
            if (j > 0) dp[i][j][k] += j * dp[j - 1][i][k];
            if (k > 0) dp[i][j][k] += k * dp[k - 1][i][j];
            dp[i][j][k] %= MOD;
        }
    }
    //REP(i, 5)REP(j, 5) REP(k, 5) {
    //cerr << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
    //}
}

int licz(int a, int b, int c) {
    //cerr << a << " " << b << " " << c << "\n";
    int res = 0;
    if (a > 0) res += a * dp[a - 1][b][c];
    if (b > 0) res += b * dp[b - 1][a][c];
    if (c > 0) res += c * dp[c - 1][b][a];
    return res;
}

void jebaj() {
    prepro();
    int n, t;
    cin >> n >> t;
    VII v(n);
    REP(i, n) {
        cin >> v[i].ST >> v[i].ND;
    }

    int res = 0;
    FOR(i, 1, (1ll << n) - 1) {
        int maska = i;
        int s = 0;
        VI w(3);
        REP(j, n) {
            if (maska & 1ll) {
                s += v[j].ST;
                w[v[j].ND - 1]++;
            }
            if (s > t) break;
            maska >>= 1ll;
        }
        if (s == t) {
            sort(ALL(w));
            res = (res + licz(w[0], w[1], w[2])) % MOD;
        }
    }
    cout << res << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    //cin >> t;
    while (t--) {
        jebaj();
    }
    return 0;
}