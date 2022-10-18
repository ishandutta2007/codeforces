#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> cnt(6, 0);
    for (char c : s)
        cnt[c - 'a']++;

    int m;
    cin >> m;
    int n = s.size();
    vector<int> masks(n, 0b111111);
    vector<int> mask_cnt(1 << 6, 0);
    for (int i = 0; i < m; i++) {
        int pos;
        string t;
        cin >> pos >> t;
        int mask = 0;
        for (char c : t)
            mask |= 1 << (c - 'a');
        masks[pos-1] = mask;
    }
    for (int ma : masks)
        mask_cnt[ma]++;
    
    int N = 8 + (1 << 6);
    int start = 0;
    int end = N - 1;

    for (int i = 0; i < n; i++) {
        bool f = false;
        mask_cnt[masks[i]]--;
        for (int j = 0; j < 6 && !f; j++) {
            if (cnt[j] == 0) continue;
            if ((masks[i] & (1 << j)) == 0) continue;

            cnt[j]--;
            bool b = true;
            for (int mm = 1; mm < (1 << 6); mm++) {
                int sum1 = 0;
                for (int k = 0; k < 6; k++) {
                    if (mm & (1 << k))
                        sum1 += cnt[k];
                }
                int sum2 = 0;
                for (int mm2 = 1; mm2 < (1 << 6); mm2++) {
                    if ((mm & mm2) == mm2)
                        sum2 += mask_cnt[mm2];
                }

                if (sum1 < sum2) {
                    b = false;
                    break;
                }
            }

            
            if (b) {
                s[i] = 'a' + j;
                f = true;
                break;
            }
            cnt[j]++;
        }
        if (!f) {
            cout << "Impossible" << '\n';
            return 0;
        }

    }
    cout << s << '\n';
}