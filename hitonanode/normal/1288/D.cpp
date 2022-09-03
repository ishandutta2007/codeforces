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
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
 

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<lint>> A(N, vector<lint>(M));
    cin >> A;
    lint lo = 0, hi = 1.1e9;
    int c1 = -1, c2 = -1;

    bool flg = true;
    while (hi - lo > 1 or flg) {
        if (hi - lo == 1) flg = false;
        lint c = lo + (hi - lo) / 2;
        vector<int> cou(1 << M, -1);
        REP(i, N) {
            int S = 0;
            REP(j, M) if (A[i][j] >= c) S += 1 << j;
            cou[S] = i;
        }
        REP(i, M) IREP(S, 1 << M) if (((S >> i) & 1) and cou[S] != -1) cou[S - (1 << i)] = cou[S];
        
        bool b = false;
        if (cou.back() != -1) {
            c1 = cou.back();
            c2 = (c1 == 0 ? 1 : 0);
            b = true;
        }
        REP(S, 1 << M) if (cou[S] > -1 and cou[(1 << M) - 1 - S] > -1) {
            b = true;
            c1 = cou[S];
            c2 = cou[(1 << M) - 1 - S];
        }
        (b ? lo : hi) = c;
    }
    cout << c1 + 1 << " " << c2 + 1 << endl;
}