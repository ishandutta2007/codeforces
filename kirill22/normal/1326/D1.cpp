#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            bool f = true;
            for (int j = 0; j < l; j++) {
                if (s[j] != s[n - j - 1] || n - j - 1 <= r) f = false;
            }
            if (f && ans.size() < 2 * i + 1) {
                ans = s.substr(0, r + 1) + s.substr(n - l, l);
            }
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            bool f = true;
            for (int j = 0; j < l; j++) {
                if (s[j] != s[n - j - 1] || n - j - 1 <= r) f = false;
            }
            if (f && ans.size() < 2 * i + 1) {
                ans = s.substr(0, r + 1) + s.substr(n - l, l);
            }
        }
        for (int i = 1; i < n; i++) {
            int l = i - 1, r = i;
            if (s[i - 1] != s[i]) continue;
            while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            bool f = true;
            for (int j = 0; j < l; j++) {
                if (s[j] != s[n - j - 1] || n - j - 1 <= r) f = false;
            }
            if (f && ans.size() < 2 * i) {
                ans = s.substr(0, r + 1) + s.substr(n - l, l);
            }
        }
        reverse(s.begin(), s.end());
        for (int i = 1; i < n; i++) {
            int l = i - 1, r = i;
            if (s[i - 1] != s[i]) continue;
            while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            bool f = true;
            for (int j = 0; j < l; j++) {
                if (s[j] != s[n - j - 1] || n - j - 1 <= r) f = false;
            }
            if (f && ans.size() < 2 * i) {
                ans = s.substr(0, r + 1) + s.substr(n - l, l);
            }
        }
        cout << ans << endl;
    }
}