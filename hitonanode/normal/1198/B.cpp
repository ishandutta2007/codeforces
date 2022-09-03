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

vector<int> val;
int D;
void build(const vector<int> &A)
{
    int N = A.size();
    int d = 0;
    while ((1 << d) < N) d++;
    D = 1 << d;
    val.assign(D * 2, -1);
    REP(i, A.size()) val[i + D - 1] = A[i];
}

void upd(int i, int a)
{
    int l = 0, r = D, now = 0; // [l, r)
    while (r - l > 1)
    {
        if (val[now] >= 0)
        {
            mmax(val[now * 2 + 1], val[now]);
            mmax(val[now * 2 + 2], val[now]);
            val[now] = -1;
        }
        int c = (l + r) / 2;
        if (i < c) r = c, now = now * 2 + 1;
        else l = c, now = now * 2 + 2;
    }
    val[now] = a;
}

void range_provide(int a)
{
    mmax(val[0], a);
}

void resolve(int now, int l, int r)
{
    if (r - l > 1)
    {
        int c = (l + r) /2;
        if (val[now] >= 0)
        {
            mmax(val[now * 2 + 1], val[now]);
            mmax(val[now * 2 + 2], val[now]);
            val[now] = -1;
        }
        resolve(now * 2 + 1, l, c);
        resolve(now * 2 + 2, c, r);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    build(A);
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        int i, p, x;
        cin >> i;
        if (i == 1)
        {
            cin >> p >> x;
            upd(p - 1, x);
        }
        else
        {
            cin >> x;
            range_provide(x);
        }
    }
    resolve(0, 0, D);
    REP(i, N) printf("%d ", val[D - 1 + i]);
    puts("");
}