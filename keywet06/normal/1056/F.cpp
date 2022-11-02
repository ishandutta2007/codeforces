#include <bits/stdc++.h>

typedef long long int64;

double MinV[100 + 1][1000 + 1];

void solve() {
    std::vector<double> Powp(1100);
    Powp[0] = 1.0;
    for (int i = 1; i < Powp.size(); ++i) Powp[i] = 10.0 / 9.0 * Powp[i - 1];
    int n;
    std::cin >> n;
    double C, T;
    std::cin >> C >> T;
    std::vector<std::pair<int64, int64> > Pro(n);
    for (int i = 0; i < n; ++i) std::cin >> Pro[i].first >> Pro[i].second;
    std::sort(Pro.begin(), Pro.end());
    std::reverse(Pro.begin(), Pro.end());
    int64 MaxS = 10 * n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= MaxS; ++j) MinV[i][j] = 1e80;
    }
    MinV[0][0] = 0;
    for (int p = 0; p < n; ++p) {
        int Val = Pro[p].second;
        double a = Pro[p].first;
        for (int i = n; i > 0; --i) {
            for (int j = MaxS; j >= 0; --j) {
                MinV[i][j] = std::min(MinV[i][j], MinV[i - 1][std::max(0, j - Val)] + a * Powp[i]);
            }
        }
    }
    int64 s = 0;
    int64 e = MaxS + 1;
    while (s + 1 < e) {
        int64 Sco = (s + e) / 2;
        int Ok = 0;
        for (int64 i = 0; i <= n; ++i) {
            double Num = MinV[i][Sco];
            double Tot = T - 10.0 * (double)(i);
            if (Tot < 0) continue;
            if (Num <= Tot) {
                Ok = 1;
            } else {
                double t = (sqrt(C * Num) - 1) / C;
                if (t >= 0 && t + Num / (1 + C * t) <= Tot) Ok = 1;
            }
        }
        if (Ok) {
            s = Sco;
        } else {
            e = Sco;
        }
    }
    std::cout << s << '\n';
}

int main() {
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}