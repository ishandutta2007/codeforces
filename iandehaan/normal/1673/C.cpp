#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair

#define MAXN 40'010
constexpr ll mod = 1e9+7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vector<int> pals;
    for (int i = 1; i < MAXN; i++) {
        string a = to_string(i);
        string b = a;
        reverse(all(b));
        if (a == b) pals.pb(i);
    }
    
    ll dp[MAXN];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int pal : pals) {
        for (int i = 0; i+pal < MAXN; i++) {
            dp[i+pal] += dp[i];
            dp[i+pal] %= mod;
        }
    }


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}