#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int a[N];

int main() {
    int i, j, k, n, q;
    string s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> q;
    for (j = 0; j < q; ++j) {
        cin >> n;
        int ans = n - 1;
        cin >> s;
        for (i = 0; i < s.size(); ++i)
        if (s[i] == '>')
            ans = min(ans, i);
        else
            ans = min(ans, (int) s.size() - i - 1);
        cout << ans << "\n";
    }
}