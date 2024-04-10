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
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

map<int, int> memo;
int za2id(int X1, int Y1, int X2, int Y2) 
{
    return X1 + 51 * (Y1 + 51 * (X2 + 51 * Y2));
}
int ask(int X1, int Y1, int X2, int Y2)
{
    int id_ = za2id(X1, Y1, X2, Y2);
    if (memo.count(id_)) return memo[id_];
    cout << "? " << X1 + 1 << " " << Y1 + 1 << " " << X2 + 1 << " " << Y2 + 1 << endl;
    cout.flush();
    int ret;
    cin >> ret;
    if (ret < 0) exit(8);
    memo[id_] = ret;
    return ret;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    A[0][0] = 1;
    int t1 = ask(0, 1, 2, 1);
    int t2 = ask(1, 0, 2, 1);
    if (t1 != t2) A[1][0] = 1;
    A[1][1] = ask(0, 0, 1, 1);

    REP(i, N - 2)
    {
        REP(j, 2)
        {
            int res = ask(i, j, i + 2, j);
            A[i + 2][j] = A[i][j] xor (!res);
        }
    }

    REP(i, N)
    {
        REP(j, N - 2)
        {
            if (i == N - 1 and j + 2 == N - 1) continue;
            int res = ask(i, j, i, j + 2);
            A[i][j + 2] = A[i][j] xor (!res);
        }
    }

    vector<vector<int>> B = A;
    REP(i, N) REP(j, N) if ((i + j) % 2) B[i][j] = 1 - B[i][j];

    int c = 0;
    while (A[c + 2][c + 2] != 0) c += 2;
    if (A[c + 2][c + 1] == 0) swap(A, B);

    dbg(A);
    dbg(B);
    if (A[c + 1][c] == A[c + 2][c])
    {
        int ret = ask(c, c, c + 2, c + 1);
        if (!ret) swap(A, B);
    }
    else
    {
        if (A[c + 2][c + 2] != A[c + 1][c]) swap(A, B);
        int ret = ask(c + 1, c, c + 2, c + 2);
        if (!ret) swap(A, B);
    }

    cout << "!" << endl;
    REP(i, N)
    {
        REP(j, N) cout << A[i][j];
        cout << endl;
    }
    cout.flush();
}