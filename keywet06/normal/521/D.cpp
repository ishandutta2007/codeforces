#include <bits/stdc++.h>

template <typename Type>
inline Type &Mid(Type &x, Type y) {
    return x < y ? x : (x = y);
}

template <typename Type>
inline Type &Mad(Type &x, Type y) {
    return x > y ? x : (x = y);
}

using int64 = long long;
using float96 = long double;
using pair = std::pair<int, int>;

const int N = 100005;

struct oper {
    int type, id;
    float96 val;
    oper(){};
    oper(int _type, int _id, float96 _val) : type(_type), id(_id), val(_val) {}
};

int k, n, m, ot, oi, ob, cnt;
int a[N];

pair as[N];

std::vector<pair> add[N];

std::vector<oper> p;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> k >> n >> m;
    for (int i = 1; i <= k; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        std::cin >> ot >> oi >> ob;
        if (ot == 1) {
            Mad(as[oi], std::make_pair(ob, i));
        } else if (ot == 2) {
            add[oi].emplace_back(ob, i);
        } else {
            p.emplace_back(3, i, ob);
        }
    }
    for (int i = 1; i <= k; ++i) {
        int64 sum = a[i];
        if (as[i].first > a[i]) {
            add[i].emplace_back(as[i].first - a[i], -as[i].second);
        }
        std::sort(add[i].begin(), add[i].end(),
                  [](pair x, pair y) { return x > y; });
        for (pair &pi : add[i]) {
            if (pi.second > 0) {
                p.emplace_back(2, pi.second, float96(sum + pi.first) / sum);
            } else {
                p.emplace_back(1, -pi.second, float96(sum + pi.first) / sum);
            }
            sum += pi.first;
        }
    }
    std::sort(p.begin(), p.end(), [](oper x, oper y) { return x.val > y.val; });
    if (p.size() > m) p.resize(m);
    std::stable_sort(p.begin(), p.end(),
                     [](oper x, oper y) { return x.type < y.type; });
    std::cout << p.size() << '\n';
    for (oper o : p) std::cout << o.id << ' ';
    std::cout << '\n';
    return 0;
}