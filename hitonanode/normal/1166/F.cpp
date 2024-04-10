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

int N, M, C, Q;

vector<map<int, int>> c2v;

struct SizeAwareUnionFind
{
    vector<int> par;
    vector<set<int>> cou;
    SizeAwareUnionFind(int N) : par(N), cou(N) { REP(i, N) par[i] = i, cou[i].insert(i); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    void unite(int x, int y) {
        x = find(x), y = find(y); if (x == y) return;
        if (cou[x].size() < cou[y].size()) swap(x, y); 
        par[y] = x, cou[x].insert(ALL(cou[y])), cou[y].clear();
    }
    int count(int x, int val) { return cou[find(x)].count(val); }
    void insert(int x, int val) { cou[find(x)].insert(val); }
    bool same(int x, int y) { return find(x) == find(y); }
};


SizeAwareUnionFind uf(0);

void add_edge()
{
    int x, y, c;
    cin >> x >> y >> c;
    uf.insert(x, y);
    uf.insert(y, x);
    if (c2v[c].count(x)) uf.unite(c2v[c][x], y);
    c2v[c][x] = y;
    if (c2v[c].count(y)) uf.unite(c2v[c][y], x);
    c2v[c][y] = x;
}

int main()
{
    cin >> N >> M >> C >> Q;
    uf = SizeAwareUnionFind(N + 1);
    c2v.resize(C + 1);

    REP(_, M) add_edge();
    REP(_, Q)
    {
        char c;
        cin >> c;
        if (c == '+') add_edge();
        else
        {
            int x, y;
            cin >> x >> y;
            if (uf.count(x, y)) puts("Yes");
            else puts("No");
        }
        
    }
}