#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<bool> > dp(2, vector<bool>(4, false));
        dp[0][x % 4] = true;
        dp[1][(x + 3) % 4] = true;
        for (int i = 0; i < n; ++i) {
            vector<vector<bool> > nx(2, vector<bool>(4, false));
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (!dp[j][k]) {
                        continue;
                    }
                    int l = (k + a[i]) % 4;
                    nx[j][l] = true;
                    l = (k ^ a[i]) % 4;
                    nx[j][l] = true;
                }
            }
            dp.swap(nx);
        }
        if (dp[0][y % 4]) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }

}