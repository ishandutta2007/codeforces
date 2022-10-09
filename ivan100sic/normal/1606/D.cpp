// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void mn(int& x, int y) {
    x = min(x, y);
}

void mx(int& x, int y) {
    x = max(x, y);
}

auto imin = [](int x, int y) { return min(x, y); };
auto imax = [](int x, int y) { return max(x, y); };

auto prefix_op(auto a, auto op) {
    for (int i : ra(1, ssize(a))) {
        a[i] = op(a[i-1], a[i]);
    }
    return a;
}

auto suffix_op(auto a, auto op) {
    for (int i = ssize(a) - 2; i >= 0; i--) {
        a[i] = op(a[i+1], a[i]);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector a(n, vector(m, 0));
        auto pl = a, ph = a, sl = a, sh = a;
        for (int i : ra(0, n)) {
            for (int& x : a[i]) cin >> x;

            pl[i] = prefix_op(a[i], imin);
            ph[i] = prefix_op(a[i], imax);
            sl[i] = suffix_op(a[i], imin);
            sh[i] = suffix_op(a[i], imax);
        }

        bool global_found = false;
        for (int j : ra(1, m)) {
            vector<array<int, 5>> vals(n);
            for (int i : ra(0, n)) {
                vals[i] = {pl[i][j-1], ph[i][j-1], sl[i][j], sh[i][j], i};
            }

            R::sort(vals);

            vector<int> tmp[5];
            for (int j : ra(0, 5)) {
                tmp[j].resize(n);
                for (int i : ra(0, n)) {
                    tmp[j][i] = vals[i][j];
                }
            }

            auto blue_left = prefix_op(tmp[1], imax);
            auto blue_right = prefix_op(tmp[2], imin);

            auto red_left = suffix_op(tmp[0], imin);
            auto red_right = suffix_op(tmp[3], imax);

            int found = -1;
            for (int j : ra(1, n)) {
                if (blue_left[j-1] < red_left[j] && blue_right[j-1] > red_right[j]) {
                    found = j;
                    break;
                }
            }

            if (found != -1) {
                global_found = true;
                string ans(n, 'R');
                for (int j : ra(0, found)) {
                    ans[vals[j][4]] = 'B';
                }

                cout << "YES\n" << ans << ' ' << j << '\n';
                break;
            }
        }

        if (!global_found) {
            cout << "NO\n";
        }
    }
    
}