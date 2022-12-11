#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int mod = 32768;
const int inf = 1e9;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    vector<int> dp(mod, inf);
    vector<vector<int> > from(mod);
    for (int i = 1; i < mod; ++i) {
        int j = (i + 1) % mod;
        from[j].pb(i);
        j = (i * 2) % mod;
        from[j].pb(i);
    }

    dp[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : from[v]) {
            if (dp[to] == inf) {
                dp[to] = dp[v] + 1;
                q.push(to);
            }
        }
    }

    int tt = 1;
    //cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << dp[a[i]] << " ";
        }
        cout << "\n";
    }

}