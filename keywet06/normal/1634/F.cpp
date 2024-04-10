#include <bits/stdc++.h>

int P;

inline int Add(int x, int y) { return (x += y) >= P ? x - P : x; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + P : x; }
inline int &Adds(int &x, int y) { return (x += y) >= P ? x -= P : x; }
inline int &Subs(int &x, int y) { return (x -= y) < 0 ? x += P : x; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, q;
    std::cin >> n >> q >> P;
    std::vector<int> F(n + 2);
    F[0] = F[1] = 1;
    for (int i = 2; i < n + 2; ++i) F[i] = Add(F[i - 1], F[i - 2]);
    std::vector<int> A(n + 2);
    int S = n + 2;
    auto AddA = [&](int i, int x) { S -= !A[i], S += !Adds(A[i], x); };
    auto SubA = [&](int i, int x) { S -= !A[i], S += !Subs(A[i], x); };
    for (int i = 0, x; i < n; ++i) std::cin >> x, AddA(i, x), SubA(i + 1, x), SubA(i + 2, x);
    for (int i = 0, x; i < n; ++i) std::cin >> x, SubA(i, x), AddA(i + 1, x), AddA(i + 2, x);
    while (q--) {
        char c;
        int l, r;
        std::cin >> c >> l >> r, --l;
        if (c == 'A') {
            AddA(l, 1), SubA(r, F[r - l]), SubA(r + 1, F[r - l - 1]);
        } else {
            SubA(l, 1), AddA(r, F[r - l]), AddA(r + 1, F[r - l - 1]);
        }
        std::cout << (S == n + 2 ? "YES" : "NO") << '\n';
    }
    return 0;
}