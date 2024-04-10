#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;

void solve() {
    int i, j, k, n;
    string s;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> s;
        int cnt = 0, sum = 0;
        bool flag = 0;
        for (j = 0; j < s.size(); ++j) {
            sum += (s[j] - '0');
            if (s[j] == '0')
                flag = true;
            if ((s[j] - '0') % 2 == 0)
                ++cnt;
        }
        if (sum % 3 == 0 && cnt >= 2 && flag)
            cout << "red\n";
        else
            cout << "cyan\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();
}