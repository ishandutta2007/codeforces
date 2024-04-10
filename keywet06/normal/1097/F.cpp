#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    const int N = 7070;
    std::vector<int> sqfree(N, 1);
    for (int i = 1; i < N; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % (j * j) == 0) {
                sqfree[i] = 0;
                break;
            }
        }
    }
    std::vector<std::bitset<N> > divs(N);
    std::vector<std::bitset<N> > muls(N);
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                divs[i].set(j);
                if (sqfree[i / j]) muls[j].set(i);
            }
        }
    }
    int n, q;
    std::cin >> n >> q;
    std::vector<std::bitset<N> > a(n);
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, v;
            std::cin >> x >> v, --x;
            a[x] = divs[v];
        } else if (op == 2) {
            int x, y, z;
            std::cin >> x >> y >> z, --x, --y, --z;
            a[x] = a[y] ^ a[z];
        } else if (op == 3) {
            int x, y, z;
            std::cin >> x >> y >> z, --x, --y, --z;
            a[x] = a[y] & a[z];
        } else if (op == 4) {
            int x, v;
            std::cin >> x >> v, --x;
            std::cout << (a[x] & muls[v]).count() % 2;
        }
    }
    std::cout << '\n';
    return 0;
}