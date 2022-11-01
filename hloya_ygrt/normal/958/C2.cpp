// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 


#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mt make_tuple
#define f first
#define s second

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { if (b < a) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// const int INF = (int)2e9;
const int maxn = 2e4 + 5, inf = 2e9;

int dp[maxn][51][100];
int a[maxn];

int main() {
    srand(time(0));

    // freopen("input.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int n, k, p;
    cin >> n >> k >> p;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= p;
    }

    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            for (int mod = 0; mod < p; mod++) {
                if (dp[i][j][mod] == -1) continue;
                // a[i] in my
                upmax(dp[i + 1][j][(mod + a[i]) % p], dp[i][j][mod]);
                upmax(dp[i + 1][j + 1][0], dp[i][j][mod] + (mod + a[i]) % p);
            }
    }
    cout << dp[n][k][0];
    return 0;
}