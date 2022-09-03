#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int solve(vector<int> v, vector<int> w) {
    int ret = 0;
    REP(i, v.size()) ret += abs(v[i] - w[i]);
    return ret;
}

int main()
{
    int N;
    cin >> N;
    vector<int> P(N / 2);
    cin >> P;
    sort(P.begin(), P.end());
    vector<int> v(N / 2);
    REP(i, v.size()) v[i] = i * 2 + 1;
    int ret = solve(v, P);
    for (auto &x : v) x++;
    chmin(ret, solve(v, P));
    cout << ret << "\n";
}