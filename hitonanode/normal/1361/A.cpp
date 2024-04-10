#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


void No()
{
    puts("-1");
    exit(0);
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> to(N);
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> T(N);
    cin >> T;
    vector<pint> v2i;
    REP(i, N) v2i.emplace_back(T[i], i);
    sort(ALL(v2i));
    vector<int> visited(N);
    for (auto [v, i] : v2i)
    {
        vector<int> ok(v + 1);
        for (auto j : to[i]) if (visited[j] and T[j] <= v) ok[T[j]] = 1;
        if (ok[v] or accumulate(ok.begin() + 1, ok.begin() + v, 0) < v - 1) No();
        visited[i] = 1;
    }
    for (auto p : v2i)
    {
        cout << p.second + 1 << ' ';
    }
    cout << '\n';
}