// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int H = 6000;

uint16_t a[H][H];
uint16_t t[H][H];

const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {1, 0, -1, 0, 0};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, qe;
    cin >> n >> qe;
    a[0][0] = n;

    vector<pair<int, int>> maybe = {{0, 0}};

    for (int x=0; x<=H; x++) {
        int f = 0;
        for (auto [i, j] : maybe) {
            uint16_t& r = a[i][j];
            if (r >= 4) {
                f = 1;
                int q = r / 4;
                r %= 4;

                t[i][j+1] += q;
                if (j == 1) {
                    t[i][0] += 2*q;
                } else if (j > 0) {
                    t[i][j-1] += q;
                }

                t[i+1][j] += q;
                if (i == 1) {
                    t[0][j] += 2*q;
                } else if (i > 0) {
                    t[i-1][j] += q;
                }

            }
        }

        if (!f) {
            break;
        }

        vector<pair<int, int>> tmp_maybe;

        for (auto [i, j] : maybe) {
            for (int dir=0; dir<5; dir++) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (x < 0 || y < 0) continue;
                if (t[x][y]) {
                    a[x][y] += t[x][y];
                    t[x][y] = 0;
                    tmp_maybe.emplace_back(x, y);
                }
            }
        }

        swap(maybe, tmp_maybe);
    }

    while (qe--) {
        int x, y;
        cin >> x >> y;
        x = abs(x);
        y = abs(y);
        if (max(x, y) >= H) {
            cout << "0\n";
        } else {
            cout << a[x][y] << '\n';
        }
    }
}