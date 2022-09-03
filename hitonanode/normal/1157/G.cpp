#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////

vector<int> swa(vector<int> vec)
{
    for (auto &v : vec) v = !v;
    return vec;
}

int N, M;
void try_to_solve(vector<vector<int>> A, vector<int> ans1_tmp, vector<int> ans2_to_operate)
{
    REP(h, N) REP(w, M) if (ans2_to_operate[w]) A[h][w] = !A[h][w];

    FOR(h, 1, N)
    {
        int su = accumulate(ALL(A[h]), 0);
        int su_pre = accumulate(ALL(A[h - 1]), 0);
        if (su == 0 and su_pre != 0) ans1_tmp[h] = !ans1_tmp[h], A[h] = swa(A[h]);
    }

    FOR(i, 1, N * M) if (A[i / M][i % M] < A[(i - 1) / M][(i - 1) % M]) return;

    puts("YES");
    for (auto v : ans1_tmp) printf("%d", v);
    puts("");
    for (auto v : ans2_to_operate) printf("%d", v);
    puts("");
    exit(0);
}

int main()
{
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    cin >> A;

    set<vector<int>> se;
    vector<int> ans1(N), ans2(M);

    REP(h, N)
    {
        if (A[h][0]) ans1[h] = !ans1[h], A[h] = swa(A[h]);
        se.insert(A[h]);
    }
    if (se.size() > 2)
    {
        puts("NO");
        return 0;
    }

    for (auto vec : se)
    {
        try_to_solve(A, ans1, vec);
        try_to_solve(A, ans1, swa(vec));
    }
    puts("NO");
    return 0;
}