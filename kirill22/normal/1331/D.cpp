#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    if ((s[6] - '0') % 2 == 0) cout << 0;
    else cout << 1;
}