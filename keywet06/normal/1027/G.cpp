#include <bits/stdc++.h>

typedef long long int64;

int64 P;

int64 mulef(int64 a, int64 b) {
    if (b == 0) return 0;
    return (a * (b % 30000LL) + mulef((a * 30000LL) % P, b / 30000LL)) % P;
}

int64 pw(int64 a, int64 b) {
    int64 ans = 1;
    for (int64 i = 1; i <= b; i <<= 1) {
        if (i & b) ans = mulef(ans, a);
        a = mulef(a, a);
    }
    return ans;
}

const int N = 10000000 + 5;

std::vector<int64> divi, divi1;
std::vector<int64> pr;

int64 ppw[100000];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int64 m, x;
    std::cin >> m >> x;
    int64 tm = m;
    P = m;
    int64 phi = 1, pp = 1;
    for (int64 i = 2; i <= N; ++i) {
        if (tm % i == 0) {
            tm /= i;
            pr.push_back(i);
            pp *= i;
            phi *= i - 1;
            while (tm % i == 0) {
                tm /= i;
                phi *= i;
            }
        }
    }
    if (tm > 1) {
        phi *= tm - 1;
        pr.push_back(tm);
        pp *= tm;
    }
    for (int64 i = 1; i * i <= phi; ++i) {
        if (phi % i == 0) {
            divi.push_back(i);
            divi.push_back(phi / i);
        }
    }
    if (divi.size() > 2 && divi[divi.size() - 1] == divi[divi.size() - 2]) divi.pop_back();
    std::sort(divi.begin(), divi.end());
    for (int64 i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            divi1.push_back(i);
            divi1.push_back(m / i);
        }
    }
    if (divi1.size() > 2 && divi1[divi1.size() - 1] == divi1[divi1.size() - 2]) divi1.pop_back();
    std::sort(divi1.begin(), divi1.end());
    divi1.pop_back();
    for (int i = 0; i < divi.size(); ++i) ppw[i] = pw(x, divi[i]);
    int64 ans = 1;
    for (int64 i : divi1) {
        int ind = 0;
        for (int64 j : divi) {
            if (i == mulef(i, ppw[ind++])) {
                int64 tpp = std::__gcd(pp, m / i);
                int64 ti = (m / i) / tpp;
                for (int64 k : pr) {
                    if (tpp % k == 0) ti *= k - 1;
                }
                ans += ti / j;
                break;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}