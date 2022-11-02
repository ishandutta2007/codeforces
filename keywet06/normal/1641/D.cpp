#include <bits/stdc++.h>

template <typename Type1, typename Type2>
inline Type1 &Mid(Type1 &x, Type2 y) {
    return x < y ? x : (x = y);
}

const int N = 100001;
const int S = 100;

struct Node {
    int Size;
    std::vector<int> a;
    std::bitset<N> *Bit;
    Node() : Size(0), a(), Bit(nullptr) {}
    ~Node() {}
    void Add(int i) {
        if (++Size > S) {
            (*Bit)[i] = 1;
        } else if (Size == S) {
            std::bitset<N> &Set = *(Bit = new std::bitset<N>());
            for (int x : a) Set[x] = 1;
            a.clear(), Set[i] = 1;
        } else {
            a.push_back(i);
        }
    }
};

inline std::bitset<N> &operator|=(std::bitset<N> &Set, Node n) {
    for (int x : n.a) Set[x] = 1;
    if (n.Bit != nullptr) Set |= *n.Bit;
    return Set;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > a(n, std::vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) std::cin >> a[i][j];
        std::cin >> a[i][0];
    }
    std::sort(a.begin(), a.end(),
              [](const std::vector<int> a, const std::vector<int> b) -> bool { return a.front() < b.front(); });
    std::map<int, Node> Map;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) Map[a[i][j]].Add(i);
    }
    int Ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (a[i].front() << 1 > Ans) break;
        std::bitset<N> Set;
        for (int j = 1; j <= m; ++j) Set |= Map[a[i][j]];
        int x = (~Set)._Find_first();
        if (x < n) Mid(Ans, a[i].front() + a[x].front());
    }
    if (Ans == INT_MAX) Ans = -1;
    std::cout << Ans << std::endl;
    return 0;
}