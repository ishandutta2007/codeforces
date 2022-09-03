#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

int main()
{
    int N;
    cin >> N;
    vector V(N, vector<int>(5));
    cin >> V;
    vector<int> ret;
    REP(i, N)
    {
        bool ok = true;
        REP(j, N) if (i != j)
        {
            REP(k, j) if (k != j and k != i)
            {
                lint m = 0;
                REP(d, 5) m += (V[k][d] - V[i][d]) * (V[j][d] - V[i][d]);
                if (m > 0) ok = false;
                if (!ok) break;
            }
            if (!ok) break;
        }
        if (ok) ret.emplace_back(i + 1);
    }
    cout << ret.size() << '\n';
    for (auto x : ret) cout << x << '\n';
}