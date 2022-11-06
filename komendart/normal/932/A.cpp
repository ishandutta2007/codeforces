#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    cout << s + t << endl;
}