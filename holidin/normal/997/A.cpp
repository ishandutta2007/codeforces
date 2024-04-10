#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    long long i, j, n, x, y;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y;
    cin >> s;
    long long  lt = 0, st = 0;
    for (i = 0; i < s.size(); ++i)
    if (s[i] == '0')
        if (st == 0) {
            st = 1;
            ++lt;
        } else
            st = st;
    else
        st = 0;
    cout << min(y * lt, max((long long)0, (lt - 1)) * x + y);
}