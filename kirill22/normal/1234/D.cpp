#include<bits/stdc++.h>

using namespace std;

vector<set<int>> a(26);
int ans, l, r, q, t, i, n;
char c;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    for (i = 0; i < n; ++i) {
        a[s[i] - 'a'].insert(i);
    }
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> i >> c;
            --i;
            a[s[i] - 'a'].erase(i);
            s[i] = c;
            a[s[i] - 'a'].insert(i);
        }
        else {
            cin >> l >> r;
            ans = 0;
            for (i = 0; i < 26; ++i) {
                auto it = a[i].lower_bound(l - 1);
                if (it != a[i].end() && *it <= r - 1) {
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }
}