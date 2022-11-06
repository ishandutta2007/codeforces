#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define sz(x) ((int) (x).size())

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s, t;
    cin >> s >> t;
    int a = count(s.begin(), s.end(), '1');
    int b = count(t.begin(), t.end(), '1');
    if (a & 1) ++a;
    if (a >= b) cout << "YES\n";
    else cout << "NO\n";

}