#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int solve()
{
    int N;
    cin >> N;
    vector<int> E(N);
    cin >> E;
    sort(ALL(E));
    int ret = 0;
    int c = 0;
    REP(i, N)
    {
        c++;
        if (c >= E[i])
        {
            c = 0;
            ret++;
        }
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}