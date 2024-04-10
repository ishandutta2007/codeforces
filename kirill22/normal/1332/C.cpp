#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, z;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < (k + 1) / 2; i++) {
            map<int, char> b;
            for (int j = 0; i + j * k < n; j++) {
                b[i + j * k] = s[i + j * k];
            }
            int ii = n - i - 1;
            for (int j = 0; ii - j * k >= 0; j++) {
                b[ii - j * k] = s[ii - j * k];
            }
            map<char, int> gist;
            int res = b.size();
            for (auto el : b) {
                gist[el.second]++;
            }
            int mx = 0;
            for (auto el : gist) mx = max(mx, el.second);
            ans += res - mx;
        }
        cout << ans << endl;
    }
}