// LUOGU_RID: 91063763
#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

#ifndef OCT_MODINT_HPP
#define OCT_MODINT_HPP

namespace Oct {

template <typename Type, Type P, typename MulType = Type>
class ModInt {
   protected:
    Type x;

   public:
    using Self = ModInt<Type, P, MulType>;
    ModInt() : x(0) {}
    ModInt(Type c) : x(c) {}
    explicit operator Type() { return x; }
    Type &Data() { return x; }
    friend Self operator+(Self a, Self b) { return (a.x += b.x) >= P ? a.x - P : a.x; }
    friend Self operator-(Self a, Self b) { return (a.x -= b.x) < 0 ? a.x + P : a.x; }
    friend Self operator*(Self a, Self b) { return MulType(a.x) * b.x % P; }
    friend Self &operator+=(Self &a, Self b) { return (a.x += b.x) >= P ? a.x -= P, a : a; }
    friend Self &operator-=(Self &a, Self b) { return (a.x -= b.x) < 0 ? a.x += P, a : a; }
    friend Self &operator*=(Self &a, Self b) { return a.x = MulType(a.x) * b.x % P, a; }
#define templ template <typename ExpType>
    templ Self Pow(ExpType Exp) {
        Self Base(*this), Ret(1);
        while (Exp) {
            if (Exp & 1) Ret *= Base;
            Base *= Base, Exp >>= 1;
        }
        return Ret;
    }
    templ Self &Pows(ExpType Exp) { return *this = Pow(Exp); }
    templ Self &PowEq(ExpType Exp) { return Pows(Exp); }
    templ Self &PowEqual(ExpType Exp) { return Pows(Exp); }
    templ friend Self Pow(Self Base, ExpType Exp) { return Base.Pow(Exp); }
#undef templ
    Self Inv() { return Pow(P - 2); }
    Self &Invs() { return Pows(P - 2); }
    Self &InvEq() { return Invs(); }
    Self &InvEqual() { return Invs(); }
    friend Self Inv(Self x) { return x.Pow(P - 2); }
    friend Self operator~(Self x) { return x.Inv(); }
    friend Self operator/(Self a, Self b) { return a * ~b; }
    friend Self &operator/=(Self &a, Self b) { return a *= ~b; }
    friend Self &operator++(Self &a) { return a += 1; }
    friend Self &operator--(Self &a) { return a -= 1; }
    friend Self operator++(Self &a, int) {
        Self Tmp = a;
        return a += 1, Tmp;
    }
    friend Self operator--(Self &a, int) {
        Self Tmp = a;
        return a -= 1, Tmp;
    }
    friend Self operator+(Self a) { return a; }
    friend Self operator-(Self a) { return 0 - a; }
    bool operator==(Self a) { return x == int(a); }
    bool operator!=(Self a) { return x != int(a); }
};

}  // namespace Oct

#endif

using uint64 = unsigned long long;
using MInt = Oct::ModInt<int, 1000000007, long long>;

const int N = 100005;
const int M = 100100;

struct Node;

struct Ptr {
    int x;
    Ptr(int cx = 0) : x(cx) {}
    Node *operator->();
};

uint64 PosV[M + 1], PosS[M + 1];
MInt Po2[M + 1];

std::mt19937_64 Rand(std::chrono::system_clock::now().time_since_epoch().count());

struct Node {
    Ptr l, r;
    uint64 v;
    inline Node(Ptr cl = 0, Ptr cr = 0, uint64 cv = 0) {}
    inline void PushDown() {
        if (!v) l->v = r->v = 0;
    }
    inline void PushUp() { v = l->v ^ r->v; }
    inline bool All1(int l, int r) { return v == (PosS[r] ^ PosS[l - 1]); }
};

const int Z = 40000005;

int PoolT;
Node Pool[Z];

inline Node *Ptr::operator->() { return Pool + x; }

inline Ptr &Copy(Ptr &u) { return Pool[++PoolT] = Pool[u.x], u = PoolT; }

inline bool Add(Ptr u, int l, int r, int x) {
    if (x <= l && u->All1(l, r)) return u->v = 0, false;
    if (l == r) return u->v = PosV[l], true;
    Copy(u->l), Copy(u->r), u->PushDown();
    int Mid = l + r >> 1;
    bool Ret = x <= Mid && Add(u->l, l, Mid, x) || Add(u->r, Mid + 1, r, x);
    return u->PushUp(), Ret;
}

inline int Less(Ptr u, Ptr v) {
    if (u->v == v->v) return 0;
    if (!(u->v && v->v)) return u->v ? -1 : 1;
    int x = Less(u->r, v->r);
    return x ? x : Less(u->l, v->l);
}

inline MInt Val(Ptr u, int l, int r) {
    if (!u->v) return 0;
    if (l == r) return Po2[l];
    int Mid = l + r >> 1;
    return Val(u->l, l, Mid) + Val(u->r, Mid + 1, r);
}

inline Ptr operator+(Ptr x, int y) { return Add(Copy(x), 1, M, y + 1), x; }
inline bool operator<(Ptr x, Ptr y) { return Less(x, y) < 0; }
inline bool operator!=(Ptr x, Ptr y) { return x->v != y->v; }
inline MInt Val(Ptr u) { return Val(u, 0, M - 1); }

int Use[N], From[N], Frw[N];
Ptr Dis[N];

std::vector<std::pair<int, int> > To[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    for (int i = 1; i <= M; ++i) PosS[i] = PosS[i - 1] ^ (PosV[i] = Rand());
    for (int i = int(Po2[0] = 1); i <= M; ++i) Po2[i] = Po2[i - 1] * 2;
    int n, m;
    std::cin >> n >> m;
    for (int u, v, x; m--; To[u].emplace_back(v, x), To[v].emplace_back(u, x)) std::cin >> u >> v >> x;
    int S, T;
    std::cin >> S >> T;
    std::priority_queue<std::pair<Ptr, int> > Que;
    Que.emplace(Dis[S], S);
    while (!Que.empty()) {
        auto [D, u] = Que.top();
        Que.pop();
        if (Use[u]) continue;
        Use[u] = true;
        if (u == T) break;
        for (auto [v, d] : To[u]) {
            if (Use[v]) continue;
            Ptr t = D + d;
            if (!Dis[v].x || Dis[v] < t) Que.emplace(Dis[v] = t, v), From[v] = u, Frw[v] = d;
        }
    }
    if (!Use[T]) return std::cout << -1 << '\n', 0;
    MInt Ans = Val(Dis[T]);
    std::cout << int(Ans) << '\n';
    std::vector<int> Sta;
    Sta.push_back(T);
    int u = T;
    while (u != S) Ans -= Po2[Frw[u]], Sta.push_back(u = From[u]);
    assert(Ans == 0);
    std::cout << Sta.size() << '\n';
    while (!Sta.empty()) std::cout << Sta.back() << " \n"[Sta.size() == 1], Sta.pop_back();
    return 0;
}