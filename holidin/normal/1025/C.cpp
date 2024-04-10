#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

int i, j, n, a, b, pr[N];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s += s;
    int ans = 0;
    for (i = 0; i < 2 * n; ++i) {
        if (i == 0 || s[i] == s[i - 1])
            pr[i] = 1;
        else
            pr[i] = pr[i - 1] + 1;
        ans = max(ans, pr[i]);
    }
    cout << min(n, ans);
}