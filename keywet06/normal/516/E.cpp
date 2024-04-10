#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin (Deb << "[Debug] at Line " << __LINE__)
#define Debug (Delin << " : ")
#define Deline (Delin << std::endl)

using int64 = long long;

template <typename _Tp>
inline _Tp Gcd(_Tp a, _Tp b) {
    return b ? Gcd(b, a % b) : a;
}

template <typename _Tp1, typename _Tp2>
inline _Tp1 ExGcd(_Tp1 a, _Tp1 b, _Tp2 &x, _Tp2 &y) {
    if (!b) return x = 1, y = 0, a;
    _Tp1 Ret = ExGcd(b, a % b, x, y);
    return x -= a / b * y, std::swap(x, y), Ret;
}

template <typename _Tp>
inline _Tp &Mid(_Tp &x, _Tp y) {
    return x < y ? x : (x = y);
}

template <typename _Tp>
inline _Tp &Mad(_Tp &x, _Tp y) {
    return x > y ? x : (x = y);
}

const int N = 100000;
const int M = N << 1;
const int64 INF = INT64_MAX;

int n, m, na, nb, g;
int a[N], b[N];
int r[M];

int64 Con1, Con2, Ans, Tmp;

std::vector<int> va[M], vb[M];

inline int64 Pow(int64 x, int64 m, int64 P) {
    if (m < 0) return 0;
    int64 Ret = 1;
    while (m) {
        if (m & 1) Ret = Ret * x % P;
        x = x * x % P, m >>= 1;
    }
    return Ret;
}

inline int64 Solve(std::vector<std::tuple<int, int, bool> > &p, int n, int m) {
    int64 Ans = -1, Len;
    std::tuple<int, int, bool> Last(p.front()), Add(Last);
    std::get<0>(Add) += n, p.push_back(Add);
    for (std::tuple<int, int, bool> &Now : p) {
        if (std::get<0>(Now) == std::get<0>(Last)) continue;
        Len = std::get<0>(Now) - std::get<0>(Last) - 1;
        if (Len || std::get<2>(Last)) Mad(Ans, std::get<1>(Last) + Len * m);
        Last = Now;
    }
    return Ans;
}

inline int64 Solve(std::vector<int> &a, std::vector<int> &b, int Id) {
    if (a.empty() && b.empty()) return INF;
    Debug << Id << "(" << a.size() << ", " << b.size() << "): ";
    int64 Ret = -1;
    std::vector<std::tuple<int, int, bool> > p;
    for (int &x : a) p.push_back(std::make_tuple(x * Con1 % n, x, false));
    for (int &x : b) p.push_back(std::make_tuple(x * Con1 % n, x, true));
    std::sort(p.begin(), p.end());
    Mad(Ret, Solve(p, n, m));
    p.clear();
    for (int &x : a) p.push_back(std::make_tuple(x * Con2 % m, x, true));
    for (int &x : b) p.push_back(std::make_tuple(x * Con2 % m, x, false));
    std::sort(p.begin(), p.end());
    Mad(Ret, Solve(p, m, n));
    Deb << (Ret == -1 ? 0 : Ret * g + Id) << std::endl;
    return Ret == -1 ? 0 : Ret * g + Id;
}

inline int64 Solve(int Id) { return Solve(va[Id], vb[Id], Id); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m, g = Gcd(n, m), n /= g, m /= g;
    ExGcd(m, n, Con1, Tmp), ExGcd(n, m, Con2, Tmp);
    Con1 = (Con1 % n + n) % n, Con2 = (Con2 % m + m) % m;
    std::cin >> na;
    for (int i = 0; i < na; ++i) std::cin >> a[i];
    std::cin >> nb;
    for (int i = 0; i < nb; ++i) std::cin >> b[i];
    if (na + nb < g) return std::cout << -1 << '\n', 0;
    for (int i = 0; i < na; ++i) va[a[i] % g].push_back(a[i] / g);
    for (int i = 0; i < nb; ++i) vb[b[i] % g].push_back(b[i] / g);
    for (int i = 0; i < g; ++i) Mad(Ans, Solve(i));
    std::cout << (Ans == INF ? -1 : Ans) << '\n';
    return 0;
}