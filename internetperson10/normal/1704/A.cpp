#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    bool ok = false;
    for(int i = 0; i < n-m+1; i++) {
        if(s1[i] == s2[0]) ok = true;
    }
    for(int i = m-1; i > 0; i--) {
        if(s1[n-m+i] != s2[i]) ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
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