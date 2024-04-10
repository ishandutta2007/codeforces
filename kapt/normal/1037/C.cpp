#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int inv(string s) {
    int n = s.size();
    int ans = n;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            ans--;
            i++;
        }
    }
    return ans;
}

main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool f = false;
    int ans = 0;
    int s = 0, len = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            ans += inv(a.substr(s, len));
            len = 0;
            s = n - 1;
            f = false;
            continue;
        }
        if (!f) {
            s = i;
            f = true;
        }
        len++;
    }
    ans += inv(a.substr(s, len));
    cout << ans;
    return 0;
}