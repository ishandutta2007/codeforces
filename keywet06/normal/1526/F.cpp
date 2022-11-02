#include <bits/stdc++.h>

const int F = 13;
const int N = 100005;

int T, n, c, pa, pb, pc, x, y, flag, ma, mas, id, ids, mass, masss, idss, idsss;
int a[N], g[N];

inline int query(int a, int b, int c) {
    int ret, d, e, f;
    std::cout << "? " << a << ' ' << b << ' ' << c << std::endl;
    std::cin >> ret;
    // if (a == b || b == c || a == c || a <= 0 || b <= 0 || c <= 0 || a > n ||
    //     b > n || c > n) {
    //     std::cout << "ERROR: " << a << ' ' << b << ' ' << c << std::endl;
    //     exit(0);
    // }
    // std::cout << "? " << a << ' ' << b << ' ' << c;
    // a = g[a], b = g[b], c = g[c];
    // d = std::abs(a - b), e = std::abs(b - c), f = std::abs(a - c);
    // if (d > e) std::swap(d, e);
    // if (e > f) std::swap(e, f);
    // if (d > e) std::swap(d, e);
    // ret = e;
    // std::cout << " : " << ret << std::endl;
    return ret;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n, c = (n - 4) / 6;
        // for (int i = 1; i <= n; ++i) g[i] = i;
        // std::random_shuffle(g + 1, g + n + 1);
        // if (g[1] > g[2]) {
        //     for (int i = 1; i <= n; ++i) g[i] = n + 1 - g[i];
        // }
        // for (int i = 1; i <= n; ++i) std::cin >> g[i];
        flag = 0;
        // std::cout << "Turn 1" << std::endl;
        for (pa = 1; pa <= F; ++pa) {
            for (pb = pa + 1; pb <= F; ++pb) {
                for (pc = pb + 1; pc <= F; ++pc) {
                    if (flag = query(pa, pb, pc) <= c) break;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        // std::cout << "Turn 2" << std::endl;
        ma = mas = mass = masss = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == pa || i == pb) continue;
            x = query(pa, pb, i);
            if (x > ma) {
                masss = mass, idsss = idss;
                mass = mas, idss = ids;
                mas = ma, ids = id;
                ma = x, id = i;
            } else if (x > mas) {
                masss = mass, idsss = idss;
                mass = mas, idss = ids;
                mas = x, ids = i;
            } else if (x > mass) {
                masss = mass, idsss = idss;
                mass = x, idss = i;
            } else if (x > masss) {
                masss = x, idsss = i;
            }
        }
        flag = 0;
        if (ma == mas) {
            if (mass == masss) {
                flag = 1, x = idss, y = idsss;
            } else {
                ids = idss;
            }
        } else if (mas == mass) {
            flag = 1, x = ids, y = idss;
        }
        if (flag) ids = query(id, x, pa) < query(id, y, pa) ? x : y;
        // std::cout << "Turn 3" << std::endl;
        a[id] = 1, a[ids] = 2;
        for (int i = 1; i <= n; ++i) {
            if (i != id && i != ids) a[i] = query(id, ids, i) + 2;
        }
        if (a[1] > a[2]) {
            for (int i = 1; i <= n; ++i) a[i] = n + 1 - a[i];
        }
        // for (int i = 1; i <= n; ++i) {
        //     if (a[i] != g[i]) {
        std::cout << "! ";
        for (int i = 1; i <= n; ++i) std::cout << a[i] << " \n"[i == n];
        std::cout << std::flush;
        //         std::cout << ": ";
        //         for (int i = 1; i <= n; ++i) std::cout << g[i] << " \n"[i ==
        //         n]; std::cout << std::flush; return 0;
        //     }
        // }
        std::cin >> x;
        if (!~x) return 0;
    }
    return 0;
}