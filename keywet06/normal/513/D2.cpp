#include <bits/stdc++.h>
using int64 = long long;
using pai = std::pair<int, int>;
const int N = 1e6 + 7;
const int inf = 0x3f3f3f3f;
const int64 INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline bool chkmax(T& a, S b) {
    return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T& a, S b) {
    return a > b ? a = b, true : false;
}
struct Bit {
    int a[N];
    void modify(int x, int v) {
        for (int i = x; i < N; i += i & -i) a[i] += v;
    }
    int sum(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & -i) ans += a[i];
        return ans;
    }
};
inline void fail() {
    std::cout << "IMPOSSIBLE" << std::endl;
    exit(0);
}
int n, m;
char s[10];
std::vector<pai> vc[N];
std::vector<int> ans;
Bit bit;
void dfs(int l, int r) {
    if (l > r) return;
    if (l == r) {
        ans.push_back(l);
        return;
    }
    int L = l, R = r;
    for (auto& t : vc[l]) {
        if (t.second) {
            chkmin(R, t.first - 1);
        } else {
            chkmax(L, t.first);
        }
        bit.modify(l, -1);
        bit.modify(t.first, 1);
    }
    for (; L <= R; L++, R--) {
        if (!bit.sum(L)) {
            dfs(l + 1, L);
            ans.push_back(l);
            dfs(L + 1, r);
            return;
        }
        if (!bit.sum(R)) {
            dfs(l + 1, R);
            ans.push_back(l);
            dfs(R + 1, r);
            return;
        }
    }
    fail();
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b >> s;
        if (b <= a) fail();
        if (s[0] == 'L') {
            vc[a].push_back(std::make_pair(b, 0));
        } else {
            vc[a].push_back(std::make_pair(b, 1));
        }
        bit.modify(a, 1);
        bit.modify(b, -1);
    }
    dfs(1, n);
    for (auto& t : ans) std::cout << t << ' ';
    std::cout << std::endl;
    return 0;
}