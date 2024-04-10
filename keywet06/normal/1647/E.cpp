#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> P(N), A(N);
    for (auto &p : P) std::cin >> p, --p;
    for (auto &a : A) std::cin >> a, --a;
    std::vector<bool> See(N, false);
    for (auto &p : P) See[p] = true;
    int Miss = N - std::accumulate(See.begin(), See.end(), 0);
    int Maxi = *std::max_element(A.begin(), A.end());
    assert((Maxi - (N - 1)) % Miss == 0);
    int Ste = (Maxi - (N - 1)) / Miss;
    std::vector<int> PP = P, Pos(N);
    iota(Pos.begin(), Pos.end(), 0);
    std::set<int> Rem(Pos.begin(), Pos.end());
    auto Summ = [&](std::vector<int> Fre, const std::vector<int> &Go) -> std::vector<int> {
        for (int i = 0; i < N; ++i) Fre[i] = Go[Fre[i]];
        return Fre;
    };
    for (int k = 0; 1 << k <= Ste; ++k) {
        if (Ste >> k & 1) Pos = Summ(Pos, PP);
        PP = Summ(PP, PP);
    }
    std::vector<std::vector<int>> Fom(N);
    for (int i = 0; i < N; ++i) Fom[Pos[i]].push_back(i);
    std::vector<int> Ans(N, -1), Atl(N, -1);
    for (int i = 0; i < N; ++i) {
        if (!Fom[i].empty()) {
            int goal = A[i], index = *min_element(Fom[i].begin(), Fom[i].end());
            Ans[index] = goal, Rem.erase(goal);
            for (int x : Fom[i]) Atl[x] = goal;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (Ans[i] < 0) Ans[i] = *Rem.lower_bound(Atl[i]), Rem.erase(Ans[i]);
    }
	for (int i = 0; i < N; ++i) std::cout << Ans[i] + 1 << " \n"[i == N - 1];
    return 0;
}