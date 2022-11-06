#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 3e5 + 5;
const int INF = 1e7;

const int MOD = 1e9 + 7;
const int P1 = 297;
const int P2 = 239;

int n, m;
vector<int> graph[maxn];

map<pair<int, int>, int> dp;
int cc = 1;

void dfs(int v, const vector< pair<int, int> > &hashval) {
    if (dp.count(hashval[v])) return;
    dp[hashval[v]] = cc++;
    for (auto u: graph[v]) {
        dfs(u, hashval);
    }
}

int power(int x, int n) {
    if (n == 0) return 1;
    if (n & 1) return x * power(x, n - 1) % MOD;
    return power(x * x % MOD, n >> 1);
}

pair<int, int> calc_hash(const vector<int> &v) {
    int ans1 = 0;
    int ans2 = 0;
    for (auto i: v) {
        ans1 += power(P1, i + 1);
        ans1 %= MOD;
        ans2 += power(P2, i + 1);
        ans2 %= MOD;
    }
    return make_pair(ans1, ans2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector< pair<int, int> > hashval(n);
    for (int i = 0; i < n; ++i) {
        graph[i].push_back(i);
        hashval[i] = calc_hash(graph[i]);
        graph[i].pop_back();
    }

    set< pair<int, int> > used;
    int cc = 1;
    vector<int> cnt(n);
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (used.count(hashval[i])) {
            continue;
        }
        used.insert(hashval[i]);
        set< pair<int, int> > tmp;
        for (auto u: graph[i]) {
            if (hashval[u] != hashval[i]) tmp.insert(hashval[u]);
        }
        ++cnt[tmp.size()];
        if (tmp.size() == 1) start = i;
    }

    int sum = accumulate(cnt.begin(), cnt.end(), 0);
    if (sum == 1 || cnt[1] == 2 && cnt[1] + cnt[2] == sum) {
        dfs(start, hashval);
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            cout << dp[hashval[i]] << ' ';
        }
    } else {
        cout << "NO\n";
    }
}