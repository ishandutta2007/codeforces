#include<bits/stdc++.h>
using namespace std;

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

const int K = 19;

void jebaj() {
    int n, q;
    cin >> n >> q;
    VI v(n);
    REP(i, n) cin >> v[i];

    vector<VI> dp(n + 1, VI(K, n));
    VI last(K, n);
    FORD(i, n - 1, 0) {
        REP(j, K) {
            if (v[i] & (1<<j)) {
                REP(jj, K) dp[i][jj] = min(dp[i][jj], dp[last[j]][jj]);
            }
        }
        REP(j, K) {
            if (v[i] & (1<<j)) {
                last[j] = i;
                dp[i][j] = i;
            }
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int c = v[b];
        bool ans = false;
        REP(j, K) if (c & (1 << j)) if (dp[a][j] <= b) if (!ans) {
            ans = true; cout << "Shi\n";
        }
        if (!ans) cout << "Fou\n";
    }
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