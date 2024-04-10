#include <bits/stdc++.h>

using int64 = long long;

const int64 P = 1000000007;
const int N = 100500;

int n, m, kol, kolb[64];
int64 ans;
int64 step2[N];
std::vector<std::vector<int> > gr;
std::vector<std::vector<int64> > w;
std::vector<int> used;
std::vector<int64> pot, matr;

void dfs(int v, int pr, int64 p) {
    used[v] = 1;
    pot[v] = p;
    ++kol;
    for (int i = 0; i < 64; ++i)
        if (p & (1ll << i)) kolb[i]++;

    for (int i = 0; i < (int)gr[v].size(); ++i) {
        int nv = gr[v][i];
        int64 ww = w[v][i];
        if (used[nv] == 0) {
            dfs(nv, v, p ^ ww);
        } else if (used[nv] == 1 && nv != pr) {
            matr.push_back(pot[nv] ^ p ^ ww);
        }
    }
    used[v] = 2;
}

void gauss() {
    int n = matr.size();
    for (int i = 0; i < n; ++i) {
        int num = std::max_element(matr.begin() + i, matr.end()) - matr.begin();
        std::swap(matr[num], matr[i]);
        if (matr[i] == 0) break;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if ((matr[j] ^ matr[i]) < matr[j]) matr[j] ^= matr[i];
            }
        }
    }
    while (!matr.empty() && matr.back() == 0) matr.pop_back();
}

int64 calcAns() {
    gauss();
    std::vector<int> um(64, 0);
    for (int64 m : matr) {
        for (int i = 0; i < 64; ++i) {
            if (m & (1ll << i)) um[i] = 1;
        }
    }
    int ms = matr.size();
    int64 dms = (1ll << ms) % P;
    int64 dms2 = ((dms % 2 == 0) ? (dms / 2) : ((dms + P) / 2));
    int64 ans = 0;
    for (int i = 0; i < 64; ++i) {
        int64 ns[2];
        int64 nans = 0;
        int64 ndeg = (1ll << i) % P;
        ns[1] = kolb[i];
        ns[0] = kol - kolb[i];
        if (!um[i]) {
            int64 v = (ns[0] * ns[1]) % P;
            v = (v * dms) % P;
            ans = (ans + v * ndeg) % P;
        } else {
            int64 v = (ns[0] * ns[1]) % P;
            v = (v * dms2) % P;
            ans = (ans + v * ndeg) % P;
            v = (ns[0] * (ns[0] - 1) / 2 + ns[1] * (ns[1] - 1) / 2) % P;
            v = (v * dms2) % P;
            ans = (ans + v * ndeg) % P;
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    gr.assign(n, std::vector<int>());
    w.assign(n, std::vector<int64>());
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        int64 ww;
        std::cin >> v1 >> v2 >> ww;
        --v1, --v2;
        gr[v1].push_back(v2);
        gr[v2].push_back(v1);
        w[v1].push_back(ww);
        w[v2].push_back(ww);
    }
    ans = 0, used.assign(n, 0), pot.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            kol = 0;
            memset(kolb, 0, sizeof(kolb));
            matr.clear();
            dfs(i, -1, 0);
            ans += calcAns();
            ans %= P;
        }
    }
    std::cout << ans % P << "\n";
    return 0;
}