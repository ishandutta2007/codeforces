#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int  i, j, n, k, q, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    cin >> q;
    for (i = 0; i < q; ++i) {
        string res = s;
        cin >> l >> r >> k;
        --l;
        --r;
        k = k % (r - l + 1);
        for (j = 0; j <= r - l; ++j)
            res[l + j] = s[l + (r - l + 1 + j - k) % (r - l + 1)];
        s = res;
    }
    cout << s;
}