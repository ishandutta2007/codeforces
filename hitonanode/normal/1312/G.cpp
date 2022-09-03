#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> trie(N + 1, vector<int>(26, -1));
    FOR(i, 1, N + 1) {
        int p;
        char c;
        cin >> p >> c;
        trie[p][c - 'a'] = i;
    }

    vector<int> use(N + 1, -1);
    int K;
    cin >> K;
    vector<int> ret(K, 1e9);
    REP(i, K) {
        int v;
        cin >> v;
        use[v] = i;
    }

    auto dfs = [&](auto &&self, int now, int d, int dauto) -> int {
        int cnt = 0;
        if (use[now] != -1) {
            ret[use[now]] = min(d, dauto);
            d = ret[use[now]];
            cnt++;
        }
        REP(i, 26) if (trie[now][i] != -1) {
            int st = self(self, trie[now][i], d + 1, min(d + 2, dauto + cnt));
            cnt += st;
        }
        return cnt;
    };

    dfs(dfs, 0, 0, 1);
    for (auto x : ret) printf("%d ", x);
}