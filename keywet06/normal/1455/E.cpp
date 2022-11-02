#include <bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<li, li> pt;

const li INF64 = li(1e18);

pt p[4];

inline bool read() {
    fore(i, 0, 4) {
        if (!(cin >> p[i].x >> p[i].y)) return false;
    }
    return true;
}

inline void solve() {
    li ans = INF64;
    fore(st, 0, 2) {
        fore(idx1, 0, 4) fore(idx2, 0, 4) fore(idy1, 0, 4) {
            li x1 = p[idx1].x;
            li x2 = p[idx2].x;
            li y1 = p[idy1].y;

            if (x1 > x2) continue;

            for (int k = -1; k <= 1; k += 2) {
                li y2 = y1 + k * abs(x1 - x2);

                vector<pt> fp = {{x1, y1}, {x2, y1}, {x2, y2}, {x1, y2}};
                sort(fp.begin(), fp.end());

                do {
                    li cur = 0;
                    fore(i, 0, 4) cur +=
                        abs(fp[i].x - p[i].x) + abs(fp[i].y - p[i].y);

                    ans = min(ans, cur);
                } while (next_permutation(fp.begin(), fp.end()));
            }
        }

        fore(i, 0, 4) swap(p[i].x, p[i].y);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    while (t--) assert(read()), solve();
    return 0;
}