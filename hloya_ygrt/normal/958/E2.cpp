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

const int INF = (int)2e9;
const int maxn = 5e5 + 5, inf = 2e9;

int a[maxn];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.s - a.f < b.s - b.f;
}

int dp[2][5001][2];
const int BUBEN = 10500;

int main() {
    srand(time(0));

    // freopen("input.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int k, n;
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    vector<pair<int, int> > rng;
    for (int i = 0; i + 1 < n; i++) {
        rng.pb(mp(a[i], a[i + 1]));
    }

    sort(all(rng), cmp);

    while (rng.size() > BUBEN) rng.pop_back();

    sort(all(rng));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 5001; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = INF;

    int t = 0;
    dp[0][0][0] = 0;

    for (int i = 0; i < rng.size(); i++) {
        for (int j = 0; j <= k; j++)
            for (int tk = 0; tk < 2; tk++) {
                if (dp[t][j][tk] == INF) continue;
                upmin(dp[t^1][j][0], dp[t][j][tk]);

                bool ok = (j < k) && (tk == 0 || (rng[i - 1].s != rng[i].f));
                if (ok)
                upmin(dp[t^1][j + 1][1], dp[t][j][tk] + rng[i].s - rng[i].f);
            }
        for (int j = 0; j <= k; j++)
            for (int tk = 0; tk < 2; tk++)
                dp[t][j][tk] = INF;
        t ^= 1;
    }
    cout << min(dp[t][k][0], dp[t][k][1]);
    return 0;
}