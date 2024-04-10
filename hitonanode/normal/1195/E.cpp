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
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
 
int N, M, A, B;
lint g0, X, Y, Z;

vector<vector<lint>> solve(const vector<vector<lint>> &M, int a)
{
    int H = M.size(), W = M[0].size();
    vector<vector<lint>> ret;
    ndarray(ret, H, W - a + 1);
    REP(h, H)
    {
        deque<int> deq;
        REP(w, a - 1)
        {
            while (!deq.empty() and M[h][deq.back()] >= M[h][w]) deq.pop_back();
            deq.push_back(w);
        }
        FOR(w, a - 1, W)
        {
            while (!deq.empty() and M[h][deq.back()] >= M[h][w]) deq.pop_back();
            deq.push_back(w);
            ret[h][w - a + 1] = M[h][deq.front()];
            if (deq.front() == w - a + 1) deq.pop_front();
        }
    }
    return ret;
}

vector<vector<lint>> transpose(const vector<vector<lint>> &H)
{
    int N = H.size(), M = H[0].size();
    vector<vector<lint>> ret;
    ndarray(ret, M, N);
    REP(i, N) REP(j, M) ret[j][i] = H[i][j];
    return ret;
}
int main()
{
    cin >> N >> M >> A >> B >> g0 >> X >> Y >> Z;
    vector<vector<lint>> H;
    ndarray(H, N, M);
    H[0][0] = g0;
    FOR(i, 1, N * M) H[i / M][i % M] = (H[(i - 1) / M][(i - 1) % M] * X + Y) % Z;
    H = solve(H, B);
    H = transpose(H);
    H = solve(H, A);
    lint ret = 0;
    for (auto vec : H) for (auto v : vec) ret += v;
    cout << ret << endl;
}