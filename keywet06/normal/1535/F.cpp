#include <bits/stdc++.h>

using int64 = long long;

class Trie {
   public:
    int tot;
    std::vector<std::vector<int>> id;
    std::vector<std::array<int, 26>> ch;
    Trie() {}
    Trie(int n) : tot(1), id(n), ch(n, std::array<int, 26>{}) {}
    std::vector<int> rev_insert(std::string &s, int k) {
        int n = s.length();
        std::vector<int> pos(n + 1);
        int p = 1;
        id[1].push_back(k);
        pos[n] = 1;
        for (int i = n - 1; ~i; --i) {
            int c = s[i] - 'a';
            if (!ch[p][c]) ch[p][c] = ++tot;
            p = ch[p][c];
            id[p].push_back(k);
            pos[i] = p;
        }
        return pos;
    }
    int query(int p, int l, int r) {
        return std::lower_bound(id[p].begin(), id[p].end(), r) -
               std::lower_bound(id[p].begin(), id[p].end(), l);
    }
};

int64 solve(std::vector<std::string> a) {
    int n = a.size();
    int m = a[0].length();
    std::sort(a.begin(), a.end());
    Trie tr(n * m + 2);
    std::vector<std::vector<int>> pos(n);
    for (int i = 0; i < n; ++i) pos[i] = tr.rev_insert(a[i], i);

    std::vector<int> lcp(n);
    for (int i = 1; i < n; ++i) {
        int j = 0;
        while (j < m && a[i][j] == a[i - 1][j]) ++j;
        lcp[i] = j;
    }
    std::vector<std::vector<int>> dec(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j)
            if (a[i][j] < a[i][j - 1]) dec[i].push_back(j);
        dec[i].push_back(m);
    }
    int64 res = (int64)n * (n - 1);
    std::vector<std::pair<int, int>> stk;
    stk.emplace_back(n, -1);
    for (int i = n - 1; ~i; --i) {
        for (int j = 1; j < int(stk.size()); ++j) {
            int l = stk[j].first, r = stk[j - 1].first;
            int p = stk[j].second;
            if (p < m) {
                p = *std::upper_bound(dec[i].begin(), dec[i].end(), p);
                res -= tr.query(pos[i][p], l, r);
            } else {
                res -= (r - l) * 2;
            }
        }
        while (stk.back().second >= lcp[i]) stk.pop_back();
        stk.emplace_back(i, lcp[i]);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::map<std::string, std::vector<std::string>> map;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        std::string t = s;
        std::sort(t.begin(), t.end());
        map[t].push_back(s);
    }
    int pre_sum = 0;
    int64 ans = 0;
    for (auto i : map) {
        auto &a = i.second;
        ans += (int64)a.size() * pre_sum * 1337;
        ans += solve(a);
        pre_sum += a.size();
    }
    std::cout << ans << '\n';
    return 0;
}