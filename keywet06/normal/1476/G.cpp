#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

template <typename Type1, typename Type2>
inline Type1 &Mid(Type1 &x, Type2 y) {
    return x < y ? x : (x = y);
}

const int N = 100005;
const int S1 = 3000;
const int S2 = 3000;

struct Query {
    int l, r, t, k, id;
    Query() {}
    Query(int L, int R, int T, int K, int Id) : l(L), r(R), t(T), k(K), id(Id) {}
    operator std::tuple<int, int, int, int, int>() { return std::make_tuple(l, r, t, k, id); }
};

int n, m, CCnt, QCnt, Nl, Nr, Nt, SCnt, LCnt;
int a[N], t[N], Ci[N], Cv[N], Cl[N], St[N], Ans[N], Num[N], NNum[N], Ll[N], Lr[N], Li[N], Lis[N], LId[N];

Query Qu[N];

inline void A(int x) {
    if (!NNum[x]++) Li[St[SCnt]] = x, x = LId[x] = St[SCnt++], Lr[Ll[2]] = x, Ll[x] = Ll[2], Lr[x] = 2, Ll[2] = x;
}

inline void R(int x) {
    if (!--NNum[x]) x = LId[x], Lr[Ll[x]] = Lr[x], Ll[Lr[x]] = Ll[x], St[--SCnt] = x;
}

inline void Add(int x) { R(Num[x]), A(++Num[x]); }
inline void Rem(int x) { R(Num[x]), A(--Num[x]); }

inline void Change(int i, int x) {
    if (i >= Nl && i <= Nr) Rem(a[i]), Add(x);
    a[i] = x;
}

inline void Addt(int t) { Change(Ci[t], Cv[t]); }
inline void Remt(int t) { Change(Ci[t], Cl[t]); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    for (int i = 1; i < N; ++i) St[i] = i + 2;
    SCnt = 1, Lr[1] = 2, Ll[2] = 1;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i], t[i] = a[i];
    for (int i = 1, O, l, r, k; i <= m; ++i) {
        std::cin >> O;
        if (O == 1) {
            std::cin >> l >> r >> k;
            ++QCnt, Qu[QCnt] = Query(l, r, CCnt, k, QCnt);
        } else {
            std::cin >> l >> k;
            ++CCnt, Ci[CCnt] = l, Cv[CCnt] = k, Cl[CCnt] = t[l], t[l] = k;
        }
    }
    std::sort(Qu + 1, Qu + QCnt + 1, [](Query a, Query b) {
        if (a.l / S1 != b.l / S1) return a.l / S1 < b.l / S1;
        if (a.t / S2 != b.t / S2) return a.t / S2 < b.t / S2;
        return a.r < b.r;
    });
    Nl = 1, Nr = 0, Nt = 0;
    for (int i = 1; i <= QCnt; ++i) {
        auto [l, r, t, k, id] = Qu[i];
        while (Nr < r) Add(a[++Nr]);
        while (Nl > l) Add(a[--Nl]);
        while (Nr > r) Rem(a[Nr--]);
        while (Nl < l) Rem(a[Nl++]);
        while (Nt < t) Addt(++Nt);
        while (Nt > t) Remt(Nt--);
        LCnt = 0;
        for (int i = Lr[1]; i != 2; i = Lr[i]) Lis[++LCnt] = Li[i];
        std::sort(Lis + 1, Lis + LCnt + 1);
        int ar = 0, s = 0, Min = INT_MAX;
        for (int al = 1; al <= LCnt; s -= NNum[Lis[al++]]) {
            while (ar < LCnt && s < k) s += NNum[Lis[++ar]];
            if (s >= k) Mid(Min, Lis[ar] - Lis[al]);
        }
        Ans[id] = Min == INT_MAX ? -1 : Min;
    }
    for (int i = 1; i <= QCnt; ++i) std::cout << Ans[i] << '\n';
    return 0;
}