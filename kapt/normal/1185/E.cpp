#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3;
string arr[MAXN];
int maxi[26], mini[26], maxj[26], minj[26];
int len[26];
int used[26];

main() {
    int t;
    cin >> t;
    while(t--) {
        int ni, nj;
        char minch = 27;
        bool f = false;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < 26; ++i) {
            mini[i] = 1e3; maxi[i] = -1;
            minj[i] = 1e3; maxj[i] = -1;
            len[i] = -1;
            used[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == '.') {
                    continue;
                }
                int ch = arr[i][j] - 'a';
                if (ch < minch) {
                    ni = i;
                    nj = j;
                    minch = ch;
                }
                mini[ch] = min(mini[ch], i);
                minj[ch] = min(minj[ch], j);
                maxi[ch] = max(maxi[ch], i);
                maxj[ch] = max(maxj[ch], j);
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (maxi[i] == -1) {
                continue;
            }
            if (mini[i] != maxi[i] && maxj[i] != minj[i]) {
                cout << "NO\n";
                f = 1;
                break;
            }
            len[i] = maxi[i] - mini[i] + maxj[i] - minj[i] + 1;
        }
        if (f) {
            continue;
        }
        vector<int> ans;
        bool fl = 1;
        for (int j = 25; j >= 0; --j) {
            if (len[j] == -1) {
                continue;
            }
            int si = mini[j];
            int sj = minj[j];
            int leni = maxi[j] - mini[j] + 1;
            int lenj = maxj[j] - minj[j] + 1;
            bool f = true;
            for (; si <= maxi[j] && sj <= maxj[j]; si += leni / len[j], sj += lenj / len[j]) {
                if (arr[si][sj] != '*') {
                    if (arr[si][sj] - 'a' != j) {
                        f = false;
                    }
                }
            }
            if (!f) {
                cout << "NO\n";
                fl = 0;
                break;
            }
            ans.push_back(j);
            si = mini[j];
            sj = minj[j];
            for (; si <= maxi[j] && sj <= maxj[j]; si += leni / len[j], sj += lenj / len[j]) {
                arr[si][sj] = '*';
            }
        }
        if (!fl) {
            continue;
        }
        reverse(ans.begin(), ans.end());
        fl = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] != '.') {
                    if (arr[i][j] != '*') {
                        fl = false;
                    }
                }
            }
        }
        if (!fl) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (ans.size() == 0) {
            cout << 0 << endl;
        } else {
            cout << ans.back() + 1 << endl;
        }
        int cnt = 0;
        for (auto i : ans) {
            while (cnt < i) {
                cout << mini[i] + 1 << " " << minj[i] + 1 << " ";
                cout << mini[i] + 1 << " " << minj[i] + 1 << endl;
                cnt++;
            }
            cnt++;
            cout << mini[i] + 1 << " " << minj[i] + 1 << " ";
            cout << maxi[i] + 1 << " " << maxj[i] + 1 << endl;
        }
    }
    return 0;
}