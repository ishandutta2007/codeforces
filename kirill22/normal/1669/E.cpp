#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = 0;
        map<string, int> cnt;
        for (auto s : a) {
            for (char c = 'a'; c <= 'k'; c++) {
                if (c == s[0]) {
                    continue;
                }
                string t = s;
                t[0] = c;
                ans += cnt[t];
            }
            for (char c = 'a'; c <= 'k'; c++) {
                if (c == s[1]) {
                    continue;
                }
                string t = s;
                t[1] = c;
                ans += cnt[t];
            }
            cnt[s]++;
        }
        cout << ans << '\n';
    }
}