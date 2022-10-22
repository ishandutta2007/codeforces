#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int r, c;
    cin >> r >> c;
    int ans = 0;
    for(int i = r-1; i >= 0; i--) {
        string s;
        cin >> s;
        for(int j = c-1; j >= 0; j--) {
            if(max(i, j) == 0) continue;
            if(i == 0 && s[c-1-j] == 'D') ans++;
            if(j == 0 && s[c-1-j] == 'R') ans++;
        }
    }
    cout << ans << '\n';
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