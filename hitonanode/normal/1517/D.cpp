#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    auto hw2i = [&](int h, int w) -> int { return h * W + w; };
    vector<vector<pint>> to(H * W);
    REP(i, H) REP(j, W - 1) {
        int a;
        cin >> a;
        to[hw2i(i, j)].emplace_back(hw2i(i, j + 1), a);
        to[hw2i(i, j + 1)].emplace_back(hw2i(i, j), a);
    }
    REP(i, H - 1) REP(j, W) {
        int a;
        cin >> a;
        to[hw2i(i, j)].emplace_back(hw2i(i + 1, j), a);
        to[hw2i(i + 1, j)].emplace_back(hw2i(i, j), a);
    }

    if (K % 2) {
        REP(i, H) {
            REP(j, W) cout << "-1 ";
            cout << '\n';
        }
        return 0;
    }

    K /= 2;
    vector<int> dmin(H * W);
    while (K--) {
        vector<int> nxt_min(H * W, 1 << 30);
        REP(i, H * W) {
            for (auto [j, w] : to[i]) chmin(nxt_min[i], dmin[j] + w);
        }
        dmin = nxt_min;
    }

    REP(i, H) {
        REP(j, W) cout << dmin[hw2i(i, j)] * 2 << ' ';
        cout << '\n';
    }
}