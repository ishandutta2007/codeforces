#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


string s;

inline int abc(int i) {
    if (i < 0 || i + 2 >= s.length())
        return 0;
    return ((s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') ? 1 : 0);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    cin >> s;
    int ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        ans += abc(i);
    }
    for (int i = 0; i < q; ++i) {
        int idx;
        string t;
        cin >> idx >> t;
        --idx;
        for (int j = idx - 2; j <= idx; ++j) {
            ans -= abc(j);
        }
        s[idx] = t[0];
        for (int j = idx - 2; j <= idx; ++j) {
            ans += abc(j);
        }
        cout << ans << '\n';
    }
    
}