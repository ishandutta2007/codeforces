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

int N;
vector<int> A, B, C;

queue<int> cand;
vector<int> req;

vector<int> waiting;

bool judge_cand(int i)
{
    if (i < 0 or i >= N - 1) return false;
    if (req[i] > 0 and A[i] != '9' and A[i + 1] != '9') return true;
    if (req[i] < 0 and A[i] != '0' and A[i + 1] != '0' and (A[i] != '1' or i)) return true;
    return false;
}

vector<pint> procedure;

lint nreq;

void finish()
{
    printf("%lld\n", nreq);
    REP(i, procedure.size())
    {
        printf("%d %d\n", procedure[i].first + 1, procedure[i].second);
        if (i + 1 == 100000) exit(0);
    }
}

void do_move(int i)
{
    if (req[i] == 0) return;
    if (req[i] > 0)
    {
        int m = min<lint>({req[i], '9' - A[i], '9' - A[i + 1]});
        if (m > 0)
        {
            req[i] -= m;
            A[i] += m;
            A[i + 1] += m;
            REP(_, m) procedure.emplace_back(i, 1);
        }
    }
    else
    {
        int m = min<lint>({-req[i], A[i] - '0' - (i == 0), A[i + 1] - '0'});
        if (m > 0)
        {
            req[i] += m;
            A[i] -= m;
            A[i + 1] -= m;
            REP(_, m) procedure.emplace_back(i, -1);
        }
    }

    if (procedure.size() > 100000) finish();

    if (i and !waiting[i - 1])
    {
        if (judge_cand(i - 1))
        {
            waiting[i - 1] = 1;
            cand.push(i - 1);
        };
    }
    if (i < N - 1 and !waiting[i + 1])
    {
        if (judge_cand(i + 1))
        {
            waiting[i + 1] = 1;
            cand.push(i + 1);
        }
    }
}

int main()
{
    cin >> N;
    A.resize(N);
    B.resize(N);
    REP(i, N)
    {
        char c;
        cin >> c;
        A[i] = c;
    }
    REP(i, N)
    {
        char c;
        cin >> c;
        B[i] = c;
    }
    C = A;
    C.push_back('0');

    req.resize(N);
    REP(i, N)
    {
        int t = B[i] - C[i];
        req[i] = t;
        C[i] += t;
        C[i + 1] += t;
    }
    if (C.back() != '0')
    {
        puts("-1");
        return 0;
    }
    C.clear();

    waiting.resize(N - 1);
    REP(i, N - 1) if (judge_cand(i)) cand.push(i), waiting[i] = 1;

    nreq = 0;
    for (auto x : req) nreq += abs(x);

    while (!cand.empty())
    {
        int i = cand.front();
        cand.pop();
        waiting[i] = 0;
        do_move(i);
    }
    finish();
}