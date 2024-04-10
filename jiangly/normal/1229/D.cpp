#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
const int fac[] = {1, 1, 2, 6, 24, 120};
int toInt(const vector<int> &p) {
    int ans = 0;
    for (int i = 0; i < p.size(); ++i) {
        int cur = p[i];
        for (int j = 0; j < i; ++j)
            if (p[j] < p[i])
                --cur;
        ans += cur * fac[p.size() - i - 1];
    }
    return ans;
}
vector<int> operator * (vector<int> lhs, const vector<int> &rhs) {
    for (int i = 0; i < lhs.size(); ++i)
        lhs[i] = rhs[lhs[i]];
    return lhs;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> perm(fac[k]);
    vector<int> p(k);
    for (int i = 0; i < k; ++i)
        p[i] = i;
    do
        perm[toInt(p)] = p;
    while (next_permutation(p.begin(), p.end()));
    vector<vector<int>> mult(fac[k], vector<int>(fac[k]));
    for (int i = 0; i < fac[k]; ++i)
        for (int j = 0; j < fac[k]; ++j) {
            auto x = perm[i] * perm[j];
            mult[i][j] = toInt(perm[i] * perm[j]);
        }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        vector<int> p(k);
        for (int j = 0; j < k; ++j) {
            cin >> p[j];
            --p[j];
        }
        a[i] = toInt(p);
    }
    vector<vector<int>> occur(n + 1, vector<int>(fac[k], n));
    for (int i = n - 1; i >= 0; --i) {
        occur[i] = occur[i + 1];
        occur[i][a[i]] = i;
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        bitset<120> cur;
        cur[0] = 1;
        int r = i;
        vector<int> gen;
        function<void(int)> dfs = [&](int x) {
            for (int g : gen) {
                int l = mult[g][x];
                if (cur[l] == 0) {
                    cur[l] = 1;
                    dfs(l);
                }
                int r = mult[x][g];
                if (cur[r] == 0) {
                    cur[r] = 1;
                    dfs(r);
                }
            }
        };
        
        while (true) {
            int nxt = -1, pos = n;
            for (int j = 0; j < fac[k]; ++j)
                if (occur[i][j] < pos && cur[j] == 0) {
                    nxt = j;
                    pos = occur[i][j];
                }
            ans += cur.count() * (pos + 1 - r);
            if (pos == n)
                break;
            r = pos + 1;
            gen.push_back(nxt);
            for (int j = 0; j < fac[k]; ++j)
                if (cur[j] == 1)
                    dfs(j);
        }
    }
    printf("%lld\n", ans - n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}