#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    int D = 20;
    vector<int> dcnt(D);
    for (auto a : A)
    {
        REP(d, D) if ((a >> d) & 1) dcnt[d]++;
    }
    vector<lint> ret(N);
    REP(d, D)
    {
        REP(i, dcnt[d]) ret[i] += 1 << d;
    }
    lint ans = 0;
    for (auto x : ret) ans += x * x;
    cout << ans << '\n';
}