#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


bool solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    cin >> A;
    int a = 0, b = 0;
    REP(i, N)
    {
        bool f = true;
        REP(j, M) if (A[i][j]) f = false;
        a += f;
    }
    REP(j, M)
    {
        bool f = true;
        REP(i, N) if (A[i][j]) f = false;
        b += f;
    }
    return min(a, b) % 2;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "Ashish" : "Vivek") << '\n';
}