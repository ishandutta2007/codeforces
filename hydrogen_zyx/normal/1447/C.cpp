#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000005;

ll a[N];
vector<int> ans;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k, sum = 0;
        ans.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool fail = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= (k + 1) / 2 && a[i] <= k) {
                cout << 1 << endl << i << endl;
                fail = 0;
                break;
            }
        }
        if (!fail) continue;
        for (int i = 1; i <= n; i++) {
            if (a[i] > (k + 1) / 2) continue;
            sum += a[i];
            ans.push_back(i);
            if (sum <= k && sum >= (k + 1) / 2) {
                fail = 0;
                break;
            }
        }
        if (fail) {
            cout << -1 << endl;
        } else {
            cout << ans.size() << endl;
            for (auto x : ans) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
}