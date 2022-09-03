#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }

using Edges = vector<vector<int>>;

// r
vector<int> tree_distance(int N, int r, Edges &e)
{
    vector<int> res(N); // res[r] = 0;
    queue<pint> q;
    q.push(pint(r, -1)); // (now, prev)
    while(!q.empty())
    {
        pint pa = q.front(); q.pop();
        if (pa.second >= 0) res[pa.first] = res[pa.second] + 1;
        for (auto nx : e[pa.first]) if (nx != pa.second) q.push(pint(nx, pa.first));
    }
    return res;
}
//  r
pint tree_diameter(int N, int r, Edges &e)
{
    vector<int> d = tree_distance(N, r, e);
    int s = max_element(d.begin(), d.end()) - d.begin();
    d = tree_distance(N, s, e);
    int t = max_element(d.begin(), d.end()) - d.begin();
    return make_pair(s, t);
}

int main()
{
    int N;
    cin >> N;
    Edges e(N);
    REP(i, N - 1) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        e[s].push_back(t);
        e[t].push_back(s);
    }
    int s, t;
    tie(s, t) = tree_diameter(N, 0, e);

    vector<int> ds = tree_distance(N, s, e);
    vector<int> dt = tree_distance(N, t, e);

    queue<int> q;
    vector<int> D(N, 1e9);
    REP(i, N) if (ds[i] + dt[i] == dt[s]) q.push(i), D[i] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto nxt : e[now]) if (D[nxt] == 1e9) D[nxt] = D[now] + 1, q.push(nxt);
    }
    int u = -1;
    int ret = -1;
    REP(i, N) if (i != s and i != t) {
        if (mmax(ret, ds[t] + D[i])) u = i;
    }
    cout << ret << "\n" << s + 1 << " " << t + 1 << " " << u + 1 << endl;
}