#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

vector<vector<int>> son;
vector<int> m;

int dfs(int now, int k)
{
    if (son[now].empty()) return 1;
    if (m[now])
    {
        int tmp = 1000000;
        for (auto nxt : son[now]) mmin(tmp, dfs(nxt, k));
        return tmp;
    }
    else
    {
        int tmp = 0;
        for (auto nxt : son[now]) tmp += dfs(nxt, k);
        return tmp;
    }
}


int main()
{
    int N;
    cin >> N;
    m.resize(N);
    cin >> m;
    son.resize(N);
    FOR(i, 1, N)
    {
        int par;
        cin >> par;
        son[par - 1].push_back(i);
    }

    int nleaf = 0;
    REP(i, N) nleaf += son[i].empty();
    int l = 1, r = nleaf + 1;
    while (r - l > 1)
    {
        int c = (l + r) / 2;
        (dfs(0, c) > nleaf - c + 1 ? r : l) = c;
    }
    cout << l << endl;
}