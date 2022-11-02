#include <bits/stdc++.h>

const int N = 1000009;
const int P = 666013;
const int Q = 666019;
const int C = 27;
const int D = 29;

std::string str;
std::set<int> mst;
std::vector<int> upd[N];

std::pair<int, int> hsh[N], cns[N];

inline std::pair<int, int> getHash(int l, int r) {
    std::pair<int, int> ans;
    ans.first = (-1LL * hsh[l - 1].first * cns[r - l + 1].first % P + hsh[r].first + P) % P;
    ans.second = (-1LL * hsh[l - 1].second * cns[r - l + 1].second % Q + hsh[r].second + Q) % Q;
    return ans;
}

inline void debug(void) {
    std::pair<int, int> x = getHash(1, 9), y = getHash(7, 15);
    exit(0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n >> str;
    str = '#' + str;
    cns[0] = std::make_pair(1, 1);
    for (int i = 1; i <= n; ++i) {
        hsh[i].first = (1LL * hsh[i - 1].first * C + (str[i] - 'a')) % P;
        hsh[i].second = (1LL * hsh[i - 1].second * D + (str[i] - 'a')) % Q;
        cns[i].first = 1LL * cns[i - 1].first * C % P;
        cns[i].second = 1LL * cns[i - 1].second * D % Q;
    }
    for (int i = 1, j = n; i < j; ++i, --j) {
        int pos = 0;
        for (int le = 1, ri = i; le <= ri;) {
            int md = (le + ri) / 2;
            if (getHash(i - md + 1, i + md - 1) == getHash(j - md + 1, j + md - 1)) {
                le = md + 1;
                pos = md;
            } else {
                ri = md - 1;
            }
        }
        upd[i - pos + 1].push_back(i);
        upd[i + 1].push_back(-i);
    }
    for (int i = 1; i <= (n + 1) / 2; ++i) {
        for (int x : upd[i]) {
            if (x > 0) {
                mst.insert(x);
            } else {
                mst.erase(x);
            }
        }
        std::cout << (mst.size() ? ((*mst.rbegin() - i) * 2 + 1) : -1) << " \n"[i == (n + 1) / 2];
    }
    return 0;
}