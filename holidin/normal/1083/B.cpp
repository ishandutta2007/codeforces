#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;

int c[N];

int main() {
    int i, j, n, k;
    string s, t, s1, t1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s >> t;
    if (s == t || k == 1) {
        cout << n;
        return 0;
    }
    for (i = 0; i < s.size(); ++i)
    if (s[i] != t[i])
        break;
    while (i < s.size()) {
        s1 += s[i];
        t1 += t[i];
        ++i;
    }
    long long ans = n - s1.size() + 2;
    c[0] = 0;
    for (i = 1; i < s1.size(); ++i) {
        c[i] = c[i - 1] * 2;
        if (s1[i] == 'a')
            ++c[i];
        if (t1[i] == 'b')
            ++c[i];
        c[i] = min(c[i], k);
        ans += min(c[i] + 2, k);
    }
    cout << ans;
}