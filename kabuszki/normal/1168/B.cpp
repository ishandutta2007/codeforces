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

void jebaj() {
    string s;
    cin >> s;
    int n = SIZE(s);
    s = s + "##################";
    VI dp(n, n - 1);
    FORD(i, n - 3, 0) {
        dp[i] = dp[i + 1];
        FOR(j, 1, 5) {
            if ((s[i] == s[i + j]) && (s[i] == s[i + j + j])) {
                dp[i] = min(dp[i], i + j + j - 1);
                break;
            }
        }
    }
    //for (auto a : dp) cerr << a << " "; cerr << "\n";
    int res = 0;
    FORD(i, n - 1, 0) {
        res += dp[i] - i + 1;
    }
    res = (n * (n + 1)) / 2 - res;
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