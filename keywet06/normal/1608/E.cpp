#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

template <typename Type, typename DType>
inline Type &Mad(Type &x, DType y) {
    return x > y ? x : (x = y);
}

const int N = 100005;
const int D = 16;
const int M = 1 << D;
const int E = M - 1;
const int ADD = 1e9;

int n, Answer;
int px[N], py[N], pc[N];

std::vector<int> ax[N], ay[N];
std::vector<int> Sort1[M], Sort2[M];

inline void Sort() {
    for (int i = 1; i <= n; ++i) px[i] += ADD, py[i] += ADD;
    for (int i = 1; i <= n; ++i) Sort1[px[i] & E].push_back(i);
    for (auto &vec : Sort1) {
        for (int &x : vec) Sort2[px[x] >> D].push_back(x);
    }
    int Last = -1, T, Now = 0;
    for (auto &vec : Sort2) {
        for (int &x : vec) T = px[x], px[x] = Now += px[x] != Last, Last = T;
    }
    for (auto &vec : Sort1) vec.clear();
    for (auto &vec : Sort2) vec.clear();
    for (int i = 1; i <= n; ++i) Sort1[py[i] & E].push_back(i);
    for (auto &vec : Sort1) {
        for (int &x : vec) Sort2[py[x] >> D].push_back(x);
    }
    Last = -1, Now = 0;
    for (auto &vec : Sort2) {
        for (int &x : vec) T = py[x], py[x] = Now += py[x] != Last, Last = T;
    }
    for (int i = 1; i <= n; ++i) ax[px[i]].push_back(i);
    for (int i = 1; i <= n; ++i) ay[py[i]].push_back(i);
}

inline int Solve1(int ca, int cb, int cc) {
    int L = 0, R = n + 1, D = n + 1, Ans = 0, Ln = 0, Rn = 0, Dn = 0;
    while (true) {
        ++Ans;
        while (D > 1 && Dn < Ans) {
            for (int &x : ax[--D]) {
                if (pc[x] == ca) {
                    Ln -= py[x] <= L;
                } else if (pc[x] == cb) {
                    Rn -= py[x] >= R;
                } else {
                    ++Dn;
                }
            }
        }
        while (L < n && Ln < Ans) {
            for (int &x : ay[++L]) Ln += pc[x] == ca && px[x] < D;
        }
        while (R > 1 && Rn < Ans) {
            for (int &x : ay[--R]) Rn += pc[x] == cb && px[x] < D;
        }
        if (Dn < Ans || Ln < Ans || Rn < Ans || L >= R) return --Ans;
    }
}
inline int Solve1() {
    int Ret = 0;
    Mad(Ret, Solve1(1, 2, 3));
    Mad(Ret, Solve1(1, 3, 2));
    Mad(Ret, Solve1(3, 1, 2));
    Mad(Ret, Solve1(3, 2, 1));
    Mad(Ret, Solve1(2, 3, 1));
    Mad(Ret, Solve1(2, 1, 3));
    return Ret;
}

inline int Solve2(int ca, int cb, int cc) {
    int L = 0, R = n + 1, Ans = 0, Ln = 0, Rn = 0, Mn = n / 3;
    while (true) {
        ++Ans;
        while (L < n && Ln < Ans) {
            for (int &x : ay[++L]) Ln += pc[x] == ca, Mn -= pc[x] == cc;
        }
        while (R > 1 && Rn < Ans) {
            for (int &x : ay[--R]) Rn += pc[x] == cb, Mn -= pc[x] == cc;
        }
        if (Ln < Ans || Rn < Ans || Mn < Ans) return --Ans;
    }
}
inline int Solve2() {
    int Ret = 0;
    Mad(Ret, Solve2(1, 2, 3));
    Mad(Ret, Solve2(1, 3, 2));
    Mad(Ret, Solve2(3, 1, 2));
    Mad(Ret, Solve2(3, 2, 1));
    Mad(Ret, Solve2(2, 3, 1));
    Mad(Ret, Solve2(2, 1, 3));
    return Ret;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> px[i] >> py[i] >> pc[i];
    Sort();
    Mad(Answer, Solve2());
    Mad(Answer, Solve1());
    for (int i = 1; i <= n; ++i) px[i] = n - px[i] + 1;
    for (int l = 1, r = n; l < r; ++l, --r) ax[l].swap(ax[r]);
    Mad(Answer, Solve1());
    for (int i = 1; i <= n; ++i) std::swap(px[i], py[i]);
    for (int i = 1; i <= n; ++i) ax[i].swap(ay[i]);
    Mad(Answer, Solve2());
    Mad(Answer, Solve1());
    for (int i = 1; i <= n; ++i) px[i] = n - px[i] + 1;
    for (int l = 1, r = n; l < r; ++l, --r) ax[l].swap(ax[r]);
    Mad(Answer, Solve1());
    std::cout << Answer * 3 << std::endl;
    return 0;
}