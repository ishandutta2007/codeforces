#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using int64 = long long;

const int N = 500000;
const int A = 1000000;

int n;
int a[N + 2];

std::vector<int> occ[A + 2];

int LoL[N + 2], LoR[N + 2];
int HiL[N + 2], HiR[N + 2];

void precalc() {
    std::vector<int> Lo, Hi;
    LoL[0] = HiL[0] = 0;
    for (int i = 1; i <= n; ++i) {
        while (Lo.empty() == false && a[Lo.back()] >= a[i]) Lo.pop_back();
        while (Hi.empty() == false && a[Hi.back()] <= a[i]) Hi.pop_back();
        LoL[i] = (Lo.empty() == false ? Lo.back() : 0);
        HiL[i] = (Hi.empty() == false ? Hi.back() : 0);
        Lo.push_back(i), Hi.push_back(i);
    }
    LoL[n + 1] = HiL[n + 1] = 0;
    Lo.clear(), Hi.clear();
    LoR[n + 1] = HiR[n + 1] = n + 1;
    for (int i = n; i >= 1; --i) {
        while (Lo.empty() == false && a[Lo.back()] >= a[i]) Lo.pop_back();
        while (Hi.empty() == false && a[Hi.back()] < a[i]) Hi.pop_back();
        LoR[i] = (Lo.empty() == false ? Lo.back() : n + 1);
        HiR[i] = (Hi.empty() == false ? Hi.back() : n + 1);
        Lo.push_back(i), Hi.push_back(i);
    }
    LoR[0] = HiR[0] = n + 1;
}

int firstR(int pos, int val) {
    int l = 0, r = (int)occ[val].size();
    while (l < r) {
        int m = (l + r) / 2;
        if (pos <= occ[val][m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return (r != (int)occ[val].size() ? occ[val][r] : n + 1);
}

int firstL(int pos, int val) {
    int l = -1, r = (int)occ[val].size() - 1;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (occ[val][m] <= pos) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return (l != -1 ? occ[val][l] : 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            occ[a[i]].push_back(i);
        }
        precalc();
        int64 answer = 0;
        for (int i = 1; i <= n; ++i) {
            std::vector<int> Dvs;
            for (int x = 1; x * x <= a[i]; ++x) {
                if (a[i] % x == 0) {
                    Dvs.push_back(x);
                    if (x * x != a[i]) Dvs.push_back(a[i] / x);
                }
            }
            for (int x : Dvs) {
                int l = firstL(i, x), r = firstR(i, x);
                int l1 = std::max(HiL[i], LoL[l]), r1 = std::min(HiR[i], LoR[r]);
                if (LoR[l] <= i) {
                    l1 = std::max(l1, LoR[l]);
                } else {
                    r1 = std::min(r1, LoR[l]);
                }
                if (i <= LoL[r]) {
                    r1 = std::min(r1, LoL[r]);
                } else {
                    l1 = std::max(l1, LoL[r]);
                }
                l = std::max(l, l1);
                r = std::min(r, r1);
                if (l <= i && i <= r) answer += (int64)(i - l1) * (r1 - i) - (int64)(i - l) * (r - i);
            }
        }
        std::cout << answer << "\n";
        for (int i = 1; i <= n; ++i) occ[a[i]].clear();
    }
    return 0;
}