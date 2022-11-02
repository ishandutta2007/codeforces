#include <bits/stdc++.h>

using int64 = long long;

const int64 logN = 20;
const int64 M = 1000000007;
const int64 INF = 1e18;

const int64 N = 100005;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int64 n;
    std::cin >> n;
    int64 A[n], B[n];
    for(int i = 0; i < n; ++i) std::cin >> A[i];
    for(int i = 0; i < n; ++i) std::cin >> B[i];
    std::vector<std::pair<int64, int64>> x1, x2, y1, y2;
    int64 ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += abs(A[i] - B[i]);
        if (A[i] < B[i]) {
            x1.push_back({A[i], B[i]});
            x2.push_back({B[i], A[i]});
        } else {
            y1.push_back({A[i], B[i]});
            y2.push_back({B[i], A[i]});
        }
    }
    int64 fin = ans;
    std::set<int64> s1;
    std::sort(x1.begin(), x1.end());
    std::sort(y2.begin(), y2.end());
    int64 cur1 = 0;
    for (auto i : x1) {
        while (cur1 < y2.size() and y2[cur1].first <= i.first) {
            s1.insert(y2[cur1].second);
            cur1++;
        }
        if (s1.size() > 0) {
            int64 last = *s1.rbegin();
            fin = std::min(fin, ans - 2 * (std::min(i.second, last) - i.first));
        }
    }
    std::set<int64> s2;
    std::sort(x1.begin(), x1.end());
    std::sort(y2.begin(), y2.end());
    int64 cur2 = 0;
    for (auto i : y2) {
        while (cur2 < x1.size() and x1[cur2].first <= i.first) {
            s2.insert(x1[cur2].second);
            cur2++;
        }
        if (s2.size() > 0) {
            int64 last = *s2.rbegin();
            fin = std::min(fin, ans - 2 * (std::min(last, i.second) - i.first));
        }
    }
    std::cout << fin << "\n";
    return 0;
}