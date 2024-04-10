#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        int x = n / m;
        int k = m % 10;
        vector<int> z(1, k);
        int tmp = (2 * k) % 10;
        while(tmp != k) {
            z.push_back(tmp);
            tmp = (tmp + k) % 10;
        }
        int sum = 0;
        for (auto c : z) {
            sum += c;
        }
        int ans = 0;
        int l = x % (z.size());
        for (int i = 0; i < l; i++) {
            ans += z[i];
        }
        cout << sum * (x / (z.size())) + ans << endl;
    }
}