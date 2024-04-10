#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    if (*max_element(A.begin(), A.end()) == -1) {
        puts("0 0");
        return;
    }
    vector<int> v;
    REP(i, N) if (A[i] == -1) {
        if (i - 1 >= 0 and A[i - 1] != -1) v.push_back(A[i - 1]);
        if (i + 1 < N and A[i + 1] != -1) v.push_back(A[i + 1]);
    }

    sort(v.begin(), v.end());
    int x = (v[0] + v.back()) / 2;
    int ret = max(abs(x - v[0]), abs(x - v.back()));
    REP(i, N - 1) if (A[i] >= 0 and A[i + 1] >= 0) mmax(ret, abs(A[i + 1] - A[i]));
    printf("%d %d\n", ret, x);
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}