#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<lint, pint>> e;
    REP(_, M)
    {
        lint x, y, w;
        cin >> x >> y >> w;
        e.emplace_back(w, pint(x, y));
    }
    sort(ALL(e));
    set<int> p_shown;
    REP(i, M)
    {
        p_shown.insert(e[i].second.first), p_shown.insert(e[i].second.second);
        if (p_shown.size() > 2 * K) break;
    }
    map<int, int> zm;
    for (auto v : p_shown) zm[v] = zm.size();

    int n = zm.size();
    vector<vector<lint>> D(n, vector<lint>(n, 1e15));
    REP(i, n) D[i][i] = 0;
    int neff = 0;
    REP(m, M)
    {
        int a = zm[e[m].second.first];
        int b = zm[e[m].second.second];
        if (e[m].first < D[a][b])
        {
            D[a][b] = D[b][a] = e[m].first;
            neff++;
            REP(j, n)
            {
                D[j][b] = D[b][j] = min(D[b][j], D[j][a] + D[a][b]);
                D[j][a] = D[a][j] = min(D[a][j], D[j][b] + D[b][a]);
            }
            REP(i, n) REP(j, n) D[i][j] = min(D[i][j], D[i][a] + D[a][j]);
        }
        if (neff >= K) break;
    }
    vector<lint> ds;
    REP(i, n) REP(j, i) ds.push_back(D[i][j]);
    sort(ALL(ds));
    cout << ds[K - 1] << endl;
}