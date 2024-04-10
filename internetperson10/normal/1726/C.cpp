#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for(int i = 0; i < 2*n-1; i++) {
        if(s[i] == '(' && s[i+1] == '(') ans++;
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