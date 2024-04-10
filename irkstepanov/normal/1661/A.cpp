#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        ll dp0 = 0, dp1 = 0;
        for (int i = 1; i < n; ++i) {
            ll nx0;
            ll nx1;
            nx0 = min(dp0 + abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]), dp1 + abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
            nx1 = min(dp0 + abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]), dp1 + abs(b[i] - b[i - 1]) + abs(a[i] - a[i - 1]));
            dp0 = nx0;
            dp1 = nx1;
        }
        cout << min(dp0, dp1) << "\n";
    }

}