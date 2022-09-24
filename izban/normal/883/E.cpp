#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (cin >> n) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        vector<string> a(m);

        vector<int> cnt(26);
        vector<int> cant(26);
        for (int j = 0; j < n; j++) if (s[j] != '*') cant[s[j] - 'a'] = 1;
        int need = 0;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            bool ok = 1;
            vector<char> has(26);
            for (int j = 0; j < n; j++) {
                if (s[j] == '*') {
                    ok &= !cant[a[i][j] - 'a'];
                    has[a[i][j] - 'a'] = 1;
                } else {
                    ok &= a[i][j] == s[j];
                }
            }
            if (!ok) continue;
            need++;
            for (int j = 0; j < 26; j++) cnt[j] += has[j];
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) ans += cnt[i] == need;
        cout << ans << endl;
    }
    
    return 0;
}