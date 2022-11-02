#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp std::make_pair

using int64 = long long;
using pair = std::pair<int, int>;

const int F = 8;
const int N = F + 5;
const int L = 100;

int T, sx, sy, d, tx, ty, num;
int use[N][N], px[N][N], py[N][N];

pair st;

std::string re;

std::map<std::string, pair> map;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    srand(time(NULL));
    std::cin >> T;
    map["Up-Left"] = mkp(-1, -1);
    map["Up"] = mkp(-1, 0);
    map["Up-Right"] = mkp(-1, 1);
    map["Left"] = mkp(0, -1);
    map["Right"] = mkp(0, 1);
    map["Down-Left"] = mkp(1, -1);
    map["Down"] = mkp(1, 0);
    map["Down-Right"] = mkp(1, 1);
    while (T--) {
        for (int i = 1; i <= F; ++i) {
            for (int j = 1; j <= F; ++j) {
                use[i][j] = 1;
                px[i][j] = i, py[i][j] = j;
            }
        }
        sx = 1, sy = 1, d = 0;
        std::cout << sx << ' ' << sy << std::endl;
        while (1) {
            std::cin >> re;
            if (re == "Done") {
                d = 1;
                break;
            }
            st = map[re];
            num = 0;
            for (int i = 1; i <= F; ++i) {
                for (int j = 1; j <= F; ++j) {
                    if (!use[i][j]) continue;
                    px[i][j] += st.fi, py[i][j] += st.se;
                    if (px[i][j] < 1 || px[i][j] > F) use[i][j] = 0;
                    if (py[i][j] < 1 || py[i][j] > F) use[i][j] = 0;
                    if (px[i][j] == sx || py[i][j] == sy) use[i][j] = 0;
                    if (px[i][j] + py[i][j] == sx + sy) use[i][j] = 0;
                    if (px[i][j] - py[i][j] == sx - sy) use[i][j] = 0;
                    num += use[i][j];
                }
            }
            if (num == 1) break;
            if (rand() & 1) {
                tx = rand() % 8 + 1;
                while (sx == tx) tx = rand() % 8 + 1;
                sx = tx;
            } else {
                ty = rand() % 8 + 1;
                while (sy == ty) ty = rand() % 8 + 1;
                sy = ty;
            }
            std::cout << sx << ' ' << sy << std::endl;
        }
        if (d) continue;
        for (int i = 1; i <= F; ++i) {
            for (int j = 1; j <= F; ++j) {
                if (!use[i][j]) continue;
                tx = px[i][j], ty = py[i][j];
            }
        }
        if (sx != 1) {
            sx = 1;
            std::cout << sx << ' ' << sy << std::endl;
            std::cin >> re;
            if (re == "Done") continue;
            st = map[re], tx += st.fi, ty += st.se;
        }
        if (sy != 1) {
            sy = 1;
            std::cout << sx << ' ' << sy << std::endl;
            std::cin >> re;
            if (re == "Done") continue;
            st = map[re], tx += st.fi, ty += st.se;
        }
        while (1) {
            ++(tx - ty < sx - sy ? sy : sx);
            std::cout << sx << ' ' << sy << std::endl;
            std::cin >> re;
            if (re == "Done") break;
            st = map[re], tx += st.fi, ty += st.se;
        }
    }
    return 0;
}