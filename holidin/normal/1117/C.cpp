#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;

vector <long long> v;

int main() {
    string s;
    long long i, j, n, k, m, x1, y1, x2, y2, dx = 0, dy = 0, dx1 = 0, dy1 = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> n;
    cin >> s;
    if (x1 == x2 && y1 == y2) {
        cout << 0;
        return 0;
    }
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == 'U')
            ++dy;
        if (s[i] == 'D')
            --dy;
        if (s[i] == 'R')
            ++dx;
        if (s[i] == 'L')
            --dx;
    }
    dx1 = 0, dy1 = 0;
    long long ans = 4e18;
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == 'U')
            ++dy1;
        if (s[i] == 'D')
            --dy1;
        if (s[i] == 'R')
            ++dx1;
        if (s[i] == 'L')
            --dx1;
        long long l = 0, r = 4e9 + 12;
        while (r - l > 1) {
            long long x = (l + r) / 2 - 1;
            long long xc = x1 + dx * x + dx1, yc = y1 + dy * x + dy1;
            if (abs(xc - x2) + abs(yc - y2) <= x * n + i + 1)
                r = x + 1;
            else
                l = x + 1;
        }
        if (l <= 4e9 + 3)
            ans = min(ans, l * n + i + 1);
    }
    if (ans >= 4e18)
        cout << -1;
    else
        cout << ans;
}