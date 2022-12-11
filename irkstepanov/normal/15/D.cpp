#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

void add(ll val, int pos, deque<pll>& q)
{
    while (!q.empty() && q.back().first >= val) {
        q.pop_back();
    }
    q.push_back(mp(val, pos));
}

ll get(deque<pll>& q)
{
    return q.front().first;
}

void del(ll val, int pos, deque<pll>& q)
{
    if (q.front().first == val && q.front().second == pos) {
        q.pop_front();
    }
}

vector<vector<ll> > cost;

bool comp(const pii& a, const pii& b)
{
    if (cost[a.first][a.second] != cost[b.first][b.second]) {
        return cost[a.first][a.second] < cost[b.first][b.second];
    }
    return a < b;
}

vector<vector<int> > fenwick;
int N, M;

void update(int i, int j)
{
    for (; i < N; i = (i | (i + 1))) {
        for (int jj = j; jj < M; jj = (jj | (jj + 1))) {
            ++fenwick[i][jj];
        }
    }
}

int get(int i, int j)
{
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        for (int jj = j; jj >= 0; jj = (jj & (jj + 1)) - 1) {
            ans += fenwick[i][jj];
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, m, a, b;
    scanf("%d%d%d%d", &n, &m, &a, &b);

    vector<vector<ll> > h(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%I64d", &h[i][j]);
        }
    }

    vector<vector<ll> > sum(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] = h[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    vector<vector<ll> > min_down(n + 1, vector<ll>(m + 1));
    for (int j = 1; j <= m; ++j) {
        deque<pll> q;
        for (int i = 1; i <= a; ++i) {
            add(h[i][j], i, q);
        }
        min_down[1][j] = get(q);
        for (int i = 2; i + a - 1 <= n; ++i) {
            del(h[i - 1][j], i - 1, q);
            add(h[i + a - 1][j], i + a - 1, q);
            min_down[i][j] = get(q);
        }
    }

    vector<vector<ll> > minn(n + 1, vector<ll>(m + 1));
    for (int i = 1; i + a - 1 <= n; ++i) {
        deque<pll> q;
        for (int j = 1; j <= b; ++j) {
            add(min_down[i][j], j, q);
        }
        minn[i][1] = get(q);
        for (int j = 2; j + b - 1 <= m; ++j) {
            del(min_down[i][j - 1], j - 1, q);
            add(min_down[i][j + b - 1], j + b - 1, q);
            minn[i][j] = get(q);
        }
    }

    cost.resize(n + 1);
    for (int i = 1; i + a - 1 <= n; ++i) {
        cost[i].resize(m + 1);
        for (int j = 1; j + b - 1 <= m; ++j) {
            cost[i][j] = sum[i + a - 1][j + b - 1] - sum[i - 1][j + b - 1] - sum[i + a - 1][j - 1] + sum[i - 1][j - 1];
            cost[i][j] -= a * b * minn[i][j];
        }
    }

    vector<pii> s;
    for (int i = 1; i + a - 1 <= n; ++i) {
        for (int j = 1; j + b - 1 <= m; ++j) {
            s.pb(mp(i, j));
        }
    }
    sort(all(s), comp);

    vector<pii> ans1;
    vector<ll> ans2;

    N = n + 1, M = m + 1;
    fenwick.resize(N);
    for (int i = 0; i < N; ++i) {
        fenwick[i].resize(M);
    }

    for (auto& p : s) {
        int x = p.first, y = p.second;
        int lf = max(x - a + 1, 0), rg = max(y - b + 1, 0);
        int cnt = get(x + a - 1, y + b - 1) - get(lf - 1, y + b - 1) - get(x + a - 1, rg - 1) + get(lf - 1, rg - 1);
        if (cnt) {
            continue;
        }
        ans1.pb(p);
        ans2.pb(cost[x][y]);
        update(x, y);
    }

    printf("%d\n", sz(ans1));
    for (int i = 0; i < sz(ans1); ++i) {
        printf("%d %d %I64d\n", ans1[i].first, ans1[i].second, ans2[i]);
    }

}