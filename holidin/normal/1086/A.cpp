#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e3 + 1;

vector <pair<int, int> > ans;

void add(int a, int b, int c, int d) {
    ans.push_back({a, b});
    while (a < c) {
        ++a;
        ans.push_back({a, b});
    }
    while (a > c) {
        --a;
        ans.push_back({a, b});
    }
    while (b < d) {
        ++b;
        ans.push_back({a, b});
    }
    while (b > d) {
        --b;
        ans.push_back({a, b});
    }
}

int main() {
    int i, j, a, b, c, d, n;
    int xa, xb, xc, ya, yb, yc;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;
    if (xa > xb) {
        swap(xa, xb);
        swap(ya, yb);
    }
    if (xa > xc) {
        swap(xa, xc);
        swap(ya, yc);
    }
    if (xb > xc) {
        swap(xb, xc);
        swap(yb, yc);
    }
    int mina = 1e9, xf = -1, yf = -1;
    for (i = xa; i <= xb; ++i)
    for (j = min(ya, yb); j <= max(ya, yb); ++j)
    if (abs(i - xc) + abs(j - yc) < mina) {
        xf = i;
        yf = j;
        mina = abs(i - xc) + abs(j - yc);
    }
    add(xa, ya, xf, yf);
    add(xf, yf, xb, yb);
    add(xc, yc, xf, yf);
    sort(ans.begin(), ans.end());
    int cnt = 0;
    for (i = 0; i < ans.size(); ++i)
    if (ans[i] != ans[i - 1])
        ++cnt;
    cout << cnt << endl;
    for (i = 0; i < ans.size(); ++i)
    if (ans[i] != ans[i - 1])
        cout << ans[i].fi << ' ' << ans[i].se << "\n";

}