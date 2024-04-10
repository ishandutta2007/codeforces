#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<int> ret;

vector<vector<int>> to;
vector<vector<int>> v;
vector<int> maxi;

int h;
int dfs(int now, int par)
{
    vector<int> ch;
    int d = 0, mi = -1;
    for (auto nxt : to[now]) if (nxt != par) {
        ch.push_back(dfs(nxt, now));
    }
    if (ch.empty()) {
        ret[now] = 0;
        v[h] = {1};
        maxi[h] = 0;
        return h++;
    }
    for (auto i : ch) if (chmax<int>(d, v[i].size())) mi = i;
    for (auto i : ch) if (i != mi) {
        int sz = v[i].size();
        REP(j, sz) {
            int t = v[mi].size() - sz + j;
            v[mi][t] += v[i][j];
            if (v[mi][t] > v[mi][maxi[mi]]) maxi[mi] = t;
            else if (v[mi][t] == v[mi][maxi[mi]] and t > maxi[mi]) maxi[mi] = t;
        }
        v[i].clear();
    }
    v[mi].push_back(1);
    if (v[mi][maxi[mi]] == 1) maxi[mi] = v[mi].size() - 1;
    ret[now] = v[mi].size() - 1 - maxi[mi];
    return mi;
}

int main()
{
    int N;
    cin >> N;
    to.resize(N);
    REP(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    ret.assign(N, 0);
    v.resize(N);
    maxi.assign(N, -1);
    dfs(0, -1);
    for (auto x : ret) printf("%d\n", x);
}