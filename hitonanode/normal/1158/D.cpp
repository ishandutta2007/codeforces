#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
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
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))

lint det(plint a, plint b) { return a.first * b.second - a.second * b.first; }
lint dot(plint a, plint b) { return a.first * b.first + a.second * b.second; }

int ccw(plint a, plint b, plint c) // a->b->c
{
    plint v1 = b - a;
    plint v2 = c - a;
    if (det(v1, v2) > 0) return 1; // 
    if (det(v1, v2) < 0) return -1; // 
    if (dot(v1, v2) < 0) return 2; // c-a-b
    if (dot(v1, v1) < dot(v2, v2)) return -2; // a-b-c
    return 0; // a-c-b
}

vector<plint> convex_hull(vector<plint> ps)
{
    if (ps.size() == 0) return vector<plint>(0);
    if (ps.size() == 1) return ps;
    sort(ALL(ps));
    int n = ps.size(), k = 0;
    vector<plint> qs(2 * n);
    REP(i, n)
    {
        while (k > 1 && ccw(qs[k - 2], qs[k - 1], ps[i]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && ccw(qs[k - 2], qs[k - 1], ps[i]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}


int main()
{
    int N;
    cin >> N;
    vector<plint> A;
    map<plint, int> p2id;
    REP(i, N)
    {
        lint x, y;
        cin >> x >> y;
        A.emplace_back(x, y);
        p2id[plint(x, y)] = i + 1;
    }
    sort(ALL(A));
    string S;
    cin >> S;

    vector<plint> ch = convex_hull(A);
    plint now = ch[0];
    vector<int> ret{p2id[now]};
    REP(t, S.length())
    {
        vector<plint> ch = convex_hull(A);
        int i = 0;
        while (ch[i] != now) i++;
        if (S[t] == 'L') now = ch[(i + 1) % ch.size()];
        else now = ch[(i - 1 + ch.size()) % ch.size()];
        int j = 0;
        while (A[j] != ch[i]) j++;
        A.erase(A.begin() + j);
        ret.push_back(p2id[now]);
    }

    int j = 0;
    while (A[j] != now) j++;
    A.erase(A.begin() + j);
    ret.push_back(p2id[A[0]]);
    for (auto v : ret) printf("%d ", v);
    puts("");
}