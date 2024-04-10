#include<bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> ans(n * m), ans2(n * m), good(m);
        int cnt = 0;
        for (int i = 0; i < n * m; i++) {
            if (s[i] == '1' && good[i % m] == 0) {
                good[i % m] = 1;
                cnt++;
            }
            ans[i] += cnt;
        }
        cnt = 0;
        for (int i = 0; i < n * m; i++) {
            if (s[i] == '1') {
                cnt++;
            }
            if (i - m >= 0 && s[i - m] == '1') {
                cnt--;
            }
            if (cnt) {
                ans2[i]++;
            }
            if (i - m >= 0) {
                ans2[i] += ans2[i - m];
            }
        }
        for (int i = 0; i < n * m; i++) {
            cout << ans[i] + ans2[i] << " ";
        }
        cout << '\n';
    }
}