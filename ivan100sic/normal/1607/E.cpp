// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

pair<int, int> mv(int x, int y, char c) {
    switch (c) {
        case 'L': return {x, y-1};
        case 'R': return {x, y+1};
        case 'U': return {x-1, y};
        case 'D': return {x+1, y};
    }
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;

        int x = 0, y = 0, lx = 0, ly = 0, rx = 0, ry = 0;
        for (char c : s) {
            tie(x, y) = mv(x, y, c);

            int lx2 = min(lx, x);
            int ly2 = min(ly, y);
            int rx2 = max(rx, x);
            int ry2 = max(ry, y);

            if (rx2 - lx2 >= n || ry2 - ly2 >= m) {
                break;
            }

            tie(lx, ly, rx, ry) = tie(lx2, ly2, rx2, ry2);
        }

        cout << 1-lx << ' ' << 1-ly << '\n';
    }
    
}