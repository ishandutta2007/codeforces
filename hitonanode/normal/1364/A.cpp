#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int solve(vector<int> v, int x)
{
    int tot = accumulate(v.begin(), v.end(), 0);
    while (v.size())
    {
        if (tot % x) return v.size();
        tot -= v.back();
        v.pop_back();
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    REP(tc, T)
    {
        int N, X;
        cin >> N >> X;
        vector<int> A(N);
        cin >> A;
        int ret = solve(A, X);
        reverse(A.begin(), A.end());
        chmax(ret, solve(A, X));
        cout << ret << '\n';
    }
}