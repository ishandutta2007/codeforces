#include <bits/stdc++.h>

using int64 = long long;

const int N = 400005;
const int M = 200000;

int64 a[N];

inline void Add(int i, int64 d) {
    while (i < N) a[i] += d, i += i & (-i);
}

inline int Sum(int i) {
    int64 Ans = 0;
    while (i) Ans += a[i], i &= i - 1;
    return Ans;
}

int T, n, CntP;
int Pri[N], MinFac[N];

std::vector<int> Facs[N];

std::vector<std::pair<int, int> > Opers[M + 1];

int64 Ans[M], ql[M], qr[M], qp[M];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    Facs[1].push_back(1);
    for (int i = 2; i < N; ++i) {
        if (!MinFac[i]) Pri[++CntP] = i, Facs[i].resize(2), Facs[i][0] = 1, Facs[i][1] = i;
        for (int j = 1, x, c, t, cs, s; j <= CntP && (x = i * Pri[j]) < N; ++j) {
            MinFac[x] = Pri[j], c = 1, t = i;
            while (t % Pri[j] == 0) t /= Pri[j], ++c;
            Facs[x] = Facs[t], Facs[x].resize(s = (cs = Facs[t].size()) * (c + 1));
            for (int k = cs; k < s; ++k) Facs[x][k] = Facs[x][k - cs] * Pri[j];
            std::sort(Facs[x].begin(), Facs[x].end());
            if (i % Pri[j] == 0) break;
        }
    }
    for (int i = 3; i <= M; ++i) {
        int n = Facs[i].size() - 1;
        Add(i, n * (n - 1) / 2);
        for (int j = 0; j < n - 1; ++j) Opers[Facs[i][j]].emplace_back(i, n - j - 1);
        int c = __builtin_ctz(i), t = i >> c, k = i << 1, e = Facs[t].size();
        int it = Facs[t].size() - 2, m = Facs[k].size(), ik = m - 2;
        int64 s = 0;
        for (int j = 0, l = 0; j < m - 2; ++j) {
            while (Facs[t][l] << c + 1 <= Facs[k][j]) ++l;
            while (it >= 0 && Facs[t][it] << c + 1 > i - Facs[k][j]) --it;
            while (ik >= 0 && Facs[k][ik] > i - Facs[k][j]) --ik;
            int x = Facs[k][j] & ((1 << c + 1) - 1) ? e - 2 - std::max(l - 1, it) : m - 3 - std::max(j, ik);
            s += x = std::max(x, 0), Opers[Facs[k][j]].emplace_back(i, x);
        }
        Add(i, s);
    }
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; ++i) std::cin >> ql[i] >> qr[i], qp[i] = i;
    std::sort(qp + 1, qp + T + 1, [](int x, int y) { return ql[x] < ql[y]; });
    for (int i = 1, cl = 1; i <= T; ++i) {
        int l = ql[qp[i]], r = qr[qp[i]], n = r - l + 1;
        while (cl < l) {
            for (auto [x, v] : Opers[cl++]) Add(x, -v);
        }
        Ans[qp[i]] = int64(n) * (n - 1) * (n - 2) / 6 - Sum(r);
    }
    for (int i = 1; i <= T; ++i) std::cout << Ans[i] << '\n';
    return 0;
}