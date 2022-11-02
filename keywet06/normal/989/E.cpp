#include <bits/stdc++.h>

const int B = 15;
const int N = 205;

int n;
int x[N], y[N];

double Pro[N], Sas[N];
double f[N][N][B];

std::vector<std::vector<int> > Lin;

std::pair<int, int> Fix(std::pair<int, int> a) {
    if (a.second == 0) return std::pair<int, int>(1, 0);
    int d = std::__gcd(a.first, a.second);
    a.first /= d, a.second /= d;
    if (a.second < 0) a.first *= -1, a.second *= -1;
    return a;
}

void Build(int r) {
    std::map<std::pair<int, int>, std::vector<int> > cnt;
    for (int i = 0; i < n; ++i) {
        if (i != r) {
            int xx = x[i] - x[r], yy = y[i] - y[r];
            cnt[Fix(std::make_pair(xx, yy))].push_back(i);
        }
    }
    int sz = cnt.size();
    for (auto u : cnt) {
        u.second.push_back(r);
        int flag = 1;
        for (auto v : u.second) {
            f[r][v][0] += 1.0 / u.second.size() / sz;
            if (v < r) flag = 0;
        }
        if (flag) Lin.push_back(u.second);
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i) Build(i);
    for (int d = 1; d < B; ++d) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    f[i][k][d] += f[i][j][d - 1] * f[j][k][d - 1];
                }
            }
        }
    }
    int q;
    std::cin >> q;
    std::cout << std::setprecision(10) << std::fixed;
    while (q--) {
        int t, m;
        std::cin >> t >> m, --t, --m;
        for (int i = 0; i < n; ++i) Pro[i] = 0;
        Pro[t] = 1;
        for (int d = 0; d < B; ++d) {
            if (m >> d & 1) {
                for (int i = 0; i < n; ++i) Sas[i] = Pro[i], Pro[i] = 0;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) Pro[i] += Sas[j] * f[i][j][d];
                }
            }
        }
        double Ans = 0;
        for (auto Li : Lin) {
            double Op = 0;
            for (auto u : Li) Op += Pro[u];
            Ans = std::max(Ans, Op / Li.size());
        }
        std::cout << Ans << '\n';
    }
    return 0;
}