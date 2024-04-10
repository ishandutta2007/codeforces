#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int xm = 0, ym = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '+') {
            int x, y; cin >> x >> y;
            if (x > y) swap(x, y);
            xm = max(x, xm); ym = max(y, ym);
        }
        else {
            int h, w; cin >> h >> w;
            if (h > w) swap(h, w);
            if (h >= xm && w >= ym) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}