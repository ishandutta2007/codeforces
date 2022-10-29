#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        vector<int> v;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0' && cnt) {
                v.push_back(cnt);
                cnt = 0;
            }
            if (s[i] == '1') cnt++;
        }
        if (cnt) v.push_back(cnt);
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < v.size(); i += 2) ans += v[i];
        cout << ans << endl;
    }
}