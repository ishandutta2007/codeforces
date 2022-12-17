#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 10;
const int inf = 1e9;

int main() {
    char c;
    int i, j, l, r, q, d, n, x, y;
    //reopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int mxm = 0, mxx = 0;
    for (i = 0; i < n; ++i) {
        cin >> c;
        if (c == '+') {
            cin >> x >> y;
            if (x > y)
                swap(x, y);
            mxm = max(mxm, x);
            mxx = max(mxx, y);
        } else {
            cin >> x >> y;
            if (x > y)
                swap(x, y);
            if (mxm <= x && mxx <= y)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}