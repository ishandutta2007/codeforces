#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x) v.push_back(x);
        }
        sort(rall(v));
        if (v.size() < 2) {
            v.resize(2, 0);
        }
        int ans = min(v[1] - 1, (int)v.size() - 2);
        if (ans < 1) {
            ans = 0;
        }
        cout << ans << "\n";
    }
}