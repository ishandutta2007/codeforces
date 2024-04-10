#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1;

map<char, int> m;

void solve() {
    int n;
    string s;
    cin >> s;
    m.clear();
    for (auto x : s)
        ++m[x];
    char ans;
    if (m['R'] >= m['S'] && m['R'] >= m['P'])
        ans = 'P';
    else if (m['S'] >= m['P'])
            ans = 'R';
        else
            ans = 'S';
    for (int i = 0; i < s.size(); ++i)
        cout << ans;
    cout << "\n";
}


int main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    cin >> test;
    for (; test > 0; test--)
        solve();
}