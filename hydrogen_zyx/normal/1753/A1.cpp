#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int vis[N];
int a[N];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += a[i];
        if (sum < 0) {
            for (int i = 1; i <= n; i++) a[i] = -a[i];
            sum = -sum;
        }
        if (sum % 2 == 1) {
            cout << -1 << endl;
            continue;
        }

        vector<pair<int, int> > v;
        v.push_back({1, 1});
        for (int i = 2; i <= n; i++) {
            if (a[i] == 1 && sum && v.back().first == v.back().second) {
                sum -= 2;
                v.pop_back();
                v.push_back({i - 1, i});
            } else {
                v.push_back({i, i});
            }
        }
        cout << v.size() << endl;
        for (auto x: v) {
            cout << x.first << ' ' << x.second << endl;
        }
    }
}