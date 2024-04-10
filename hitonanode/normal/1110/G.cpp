#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


bool solve()
{
    int N;
    cin >> N;
    vector<vector<int>> e(N);
    REP(_, N - 1)
    {
        int v, u;
        cin >> v >> u;
        v--, u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    string S;
    cin >> S;
    int Nw = 0;
    for (auto c : S) Nw += (c == 'W');

    if (N < 3) return false;
    if (N == 3) return Nw >= 2;

    //  N >= 4
    REP(i, N) if (e[i].size() >= 4) return true;

    //  3
    REP(i, N) if (e[i].size() == 3)
    {
        int ne = 0;
        for (auto nxt : e[i]) if (e[nxt].size() > 1) ne++;
        if (ne >= 2) return true;
    }

    REP(i, N) if (S[i] == 'W')
    {
        if (e[i].size() >= 2) return true;
        for (auto nxt : e[i]) if (e[nxt].size() >= 3) return true;
    }

    if (Nw == 2) return N % 2;
    if (Nw == 1)
    {
        REP(i, N) if (e[i].size() == 3) return N % 2 == 0;
    }
    if (Nw == 0)
    {
        int nt = 0;
        REP(i, N) if (e[i].size() == 3) nt++;
        if (nt >= 2) return N % 2;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "White" : "Draw") << endl;
}