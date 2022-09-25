#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        int n = 0, ans = 10;
        for (char c : s) n += c == '?';
        for (int i = 0; i < (1 << n); i += 1) {
            int p = 0, x[2] = {0, 0};
            for (int j = 0, k = 0; j < 10; j += 1) {
                p += 1;
                if (s[j] != '?') x[j & 1] += s[j] - '0';
                else x[j & 1] += (i >> k ++) & 1;
                if (x[0] > x[1] + (10 - j) / 2) break;
                if (x[1] > x[0] + (10 - j - 1) / 2) break;
            }
            ans = min(ans, p);
        }
        cout << ans << "\n";
    }
    return 0;
}