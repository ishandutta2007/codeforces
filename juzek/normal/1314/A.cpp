#ifndef LOCAL
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim>
struct rge {
    c b, e;
};

sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }

sim> auto dud(c *r) -> decltype(cerr << *r);

sim> char dud(...);

struct muu {
#ifdef LOCAL
    stringstream a;

    ~muu() { cerr << a.str() << endl; }

    R22(<) a << boolalpha << g;
        ris; }

    R22(==) ris << range(begin(g), end(g)); }

    sim mor rge<c> u) {
        a << "[";
        for (c i = u.b; i != u.e; ++i)
            *this << ", " + 2 * (i == u.b) << *i;
        ris << "]";
    }

    sim, class m mor pair<m, c> r) { ris << "(" << r.first << ", " << r.second << ")"; }

#else
    sim mor const c&){ris;}
#endif
};

#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair<int, int>;
using ld = long double;
using ll = long long;

int pos[1000007];
int koszt[1000007];
std::map<int, vector<int>> m;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &pos[i]);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &koszt[i]);
        m[pos[i]].push_back(koszt[i]);
    }
    std::priority_queue<pair<int, int>> Q;
    int last_pos = -1;
    long long wyn = 0;
    for (auto &it : m) {
        while (!Q.empty() && last_pos < it.first) {
            auto co = Q.top();
            Q.pop();
            wyn += (last_pos - co.second) * (long long) co.first;
            last_pos++;
        }
        for (auto it2 : it.second)
            Q.push({it2, it.first});
        last_pos = it.first;
    }
    while (!Q.empty()) {
        auto co = Q.top();
        Q.pop();
        wyn += (last_pos - co.second) * (long long) co.first;
        last_pos++;
    }
    printf("%lld", wyn);
    return 0;
}