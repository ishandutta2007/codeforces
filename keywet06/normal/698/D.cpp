#include <bits/stdc++.h>

using int64 = long long;
using Poi = std::complex<int64>;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

struct shooter {
    Poi Org;
    std::map<std::pair<int, int>, std::vector<std::pair<int64, int>>> Haf;
    shooter(Poi Org) : Org(Org) {}
    void precalc(std::vector<Poi> &Tar) {
        for (int i = 0; i < (int)Tar.size(); ++i) {
            Poi dir = Tar[i] - Org;
            int64 dist2 = norm(dir);
            dir /= gcd(abs(dir.imag()), abs(dir.real()));
            std::pair<int, int> dir2 = std::make_pair(dir.real(), dir.imag());
            Haf[dir2].push_back(std::make_pair(dist2, i));
        }
        for (auto &it : Haf) sort(it.second.begin(), it.second.end());
    }
    void underfire(Poi target, int Lim, std::vector<int> &Res) {
        Poi dir = target - Org;
        int64 dist2 = norm(dir);
        dir /= gcd(abs(dir.imag()), abs(dir.real()));
        std::pair<int, int> dir2 = std::make_pair(dir.real(), dir.imag());
        std::vector<std::pair<int64, int>> &Pp = Haf[dir2];
        Res.clear();
        for (int i = 0; i < (int)Pp.size() && (int)Res.size() < Lim && Pp[i].first < dist2; ++i)
            Res.push_back(Pp[i].second);
    }
};

std::vector<shooter> SHoo;
std::vector<Poi> Tar;

bool brute(int can, std::vector<int> Tol) {
    const int many = __builtin_popcount(can);
    if (Tol.empty()) return true;
    if ((int)Tol.size() > many) return false;
    std::vector<int> Mid;
    for (int i = 0; i < (int)SHoo.size(); ++i) {
        if (!(can & (1 << i))) continue;
        for (int Mon : Tol) {
            SHoo[i].underfire(Tar[Mon], many, Mid);
            if ((int)Mid.size() < many) {
                std::vector<int> Tok = Tol;
                Tok.insert(Tok.end(), Mid.begin(), Mid.end());
                sort(Tok.begin(), Tok.end());
                Tok.resize(unique(Tok.begin(), Tok.end()) - Tok.begin());
                for (int j = (int)Tok.size() - 1; j >= 0; --j) {
                    if (Tok[j] == Mon) {
                        Tok[j] = Tok.back();
                        Tok.pop_back();
                    }
                }
                if (brute(can ^ (1 << i), Tok)) return true;
            }
        }
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int k, n;
    std::cin >> k >> n;
    for (int i = 0, x, y; i < k; ++i) {
        std::cin >> x >> y;
        SHoo.push_back(shooter(Poi(x, y)));
    }
    for (int i = 0, x, y; i < n; ++i) {
        std::cin >> x >> y;
        Tar.push_back(Poi(x, y));
    }
    for (int i = 0; i < k; ++i) SHoo[i].precalc(Tar);
    int Res = 0;
    for (int i = 0; i < n; ++i) {
        if (brute((1 << k) - 1, {i})) ++Res;
    }
    printf("%d\n", Res);
    return 0;
}