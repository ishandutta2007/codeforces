#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

int solve()
{
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;
    vector<vector<int>> cnt(20, vector<int>(20));
    REP(i, N) cnt[A[i] - 'a'][B[i] - 'a']++;
    int ret = 0;
    REP(i, 20)
    {
        int t = -1;
        REP(j, 20) if (cnt[i][j] and j != i)
        {
            t = j;
            break;
        }
        if (t < 0) continue;
        if (t < i) return -1;
        ret++;
        FOR(j, i + 1, 20) cnt[t][j] += cnt[i][j];
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}