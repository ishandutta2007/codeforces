#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;

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
        ll l, r, x;
        cin >> l >> r >> x;
        ll a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "0\n";
            continue;
        }
        if (abs(a - b) >= x) {
            cout << "1\n";
            continue;
        }
        int ans = inf;
        if (a - l >= x) {
            if (b >= l + x) {
                ans = min(ans, 2);
            } else if (b <= r - x) {
                ans = min(ans, 3);
            }
        }

        if (r - a >= x) {
            if (b <= r - x) {
                ans = min(ans, 2);
            } else if (b >= l + x) {
                ans = min(ans, 3);
            }
        }
        if (ans == inf) {
            ans = -1;
        }
        cout << ans << "\n";
    }

}