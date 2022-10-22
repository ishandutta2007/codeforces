#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    map<char, int> m;
    for(int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 2; j++) {
            m[s[j]]++;
        }
    }
    // 2 2 : 1
    // 3 1 : 1
    // 2 1 1 : 2
    // 1 1 1 1 : 3
    cout << m.size() - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}