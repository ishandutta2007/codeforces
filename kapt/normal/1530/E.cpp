#include <bits/stdc++.h>
using namespace std;

const int MAXC = 30;
int cnt[MAXC];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        string s;
        cin >> s;
        int n = s.size();
        fill(cnt, cnt + MAXC, 0);
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        int k;
        /**if (s.size() > MAXC) {
            s.clear();
            for (int i = 0; i < MAXC; ++i) {
                if (cnt[i]) {
                    s.push_back('a' + i);
                }
            }
            k = s.size();
        } else {*/
        sort(s.begin(), s.end());
        k = unique(s.begin(), s.end()) - s.begin();
        /// }
        if (k == 1) {
            cout << s << "\n";
            continue;
        }
        int v = -1;
        for (int i = 0; i < MAXC; ++i) {
            if (cnt[i] == 1) {
                v = i;
                break;
            }
        }
        if (v != -1) {
            cout << char('a' + v);
            for (int i = 0; i < MAXC; ++i) {
                if (i == v) continue;
                while (cnt[i]--) {
                    cout << char('a' + i);
                }
            }
            cout << "\n";
            continue;
        }
        if (cnt[s[0] - 'a'] <= (n + 2) / 2) {
            int cur = 1;
            for (int i = 0; i < n; ++i) {
                if ((i == 0 || i % 2 == 1) && cnt[s[0] - 'a'] > 0) {
                    cout << s[0];
                    cnt[s[0] - 'a']--;
                } else {
                    cout << s[cur];
                    cnt[s[cur] - 'a']--;
                    if (cnt[s[cur] - 'a'] == 0) {
                        cur++;
                    }
                }
            }
            cout << "\n";
            continue;
        }
        if (k == 2) {
            int a = s[0] - 'a';
            int b = s[1] - 'a';
            cout << s[0];
            for (int i = 0; i < cnt[b]; ++i) {
                cout << s[1];
            }
            for (int i = 1; i < cnt[a]; ++i) {
                cout << s[0];
            }
            cout << "\n";
            continue;
        }
        int a = s[0] - 'a';
        int b = s[1] - 'a';
        int c = s[2] - 'a';
        cout << s[0] << s[1];
        for (int i = 1; i < cnt[a]; ++i) {
            cout << s[0];
        }
        cout << s[2];
        for (int i = 1; i < cnt[b]; ++i) {
            cout << s[1];
        }
        for (int i = 1; i < cnt[c]; ++i) {
            cout << s[2];
        }
        for (int i = 3; i < k; ++i) {
            for (int j = 0; j < cnt[s[i] - 'a']; ++j) {
                cout << s[i];
            }
        }
        cout << "\n";

    }
    return 0;
}