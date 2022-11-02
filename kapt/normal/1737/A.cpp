#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        string ans;
        for (int i = 0; i < n; i += n / k) {
            for (int j = 0; j <= n / k; ++j) {
                if (j < n / k && cnt[j]) {
                    cnt[j]--;
                } else {
                    ans.push_back('a' + j);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}