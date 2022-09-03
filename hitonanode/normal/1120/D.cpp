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

vector<vector<int>> e;
vector<lint> costs;

set<int> ret;
lint total;

vector<int> vall, vm1;
vector<lint> pall, pm1;

void dfs(int now, int prv)
{
    bool flg = false;

    lint ptot = 0;
    for (auto nxt : e[now]) if (nxt != prv)
    {
        flg = true;
        dfs(nxt, now);
        ptot += pall[nxt];
    }

    if (!flg)
    {
        pall[now] = costs[now];
        pm1[now] = 0;
        return;
    }

    pm1[now] = pall[now] = ptot;
    for (auto nxt : e[now]) if (nxt != prv)
    {
        mmin(pall[now], ptot - pall[nxt] + pm1[nxt] + costs[now]);
        mmin(pm1[now], ptot - pall[nxt] + pm1[nxt]);
    }
}

void dfs2(int now, int prv)
{
    if (costs[now] == 0) ret.insert(now);

    lint c0tot = 0;
    bool flg = false;
    for (auto nxt : e[now]) if (nxt != prv)
    {
        flg = true;
        c0tot += pall[nxt];
    }

    if (vall[now])
    {
        if (!flg) ret.insert(now);

        if (c0tot == pall[now])
        {
            for (auto nxt : e[now]) if (nxt != prv) vall[nxt] = 1;
        }
        else
        {
            ret.insert(now);
        }

        set<int> s;
        for (auto nxt : e[now]) if (nxt != prv)
        {
            if (c0tot - pall[nxt] + pm1[nxt] + costs[now] == pall[now])
            {
                ret.insert(now);
                s.insert(nxt);
            }
        }
        if (s.size() > 1)
        {
            for (auto nxt : e[now]) if (nxt != prv) vall[nxt] = vm1[nxt] = 1;
        }
        if (s.size() == 1)
        {
            vm1[*s.begin()] = 1;
            for (auto nxt : e[now]) if (nxt != prv and nxt != *s.begin()) vall[nxt] = 1;
        }
    }

    if (vm1[now])
    {
        // if (c0tot == pm1[now])
        // {
        //     for (auto nxt : e[now]) if (nxt != prv) vall[nxt] = 1;
        // }

        set<int> s;
        for (auto nxt : e[now]) if (nxt != prv)
        {
            if (c0tot - pall[nxt] + pm1[nxt] == pm1[now]) s.insert(nxt);
        }
        if (s.size() > 1)
        {
            for (auto nxt : e[now]) if (nxt != prv) vall[nxt] = vm1[nxt] = 1;
        }
        if (s.size() == 1)
        {
            vm1[*s.begin()] = 1;
            for (auto nxt : e[now]) if (nxt != prv and nxt != *s.begin()) vall[nxt] = 1;
        }
    }

    for (auto nxt : e[now]) if (nxt != prv) dfs2(nxt, now);
}

int main()
{
    int N;
    cin >> N;
    costs.resize(N);
    cin >> costs;
    e.resize(N);
    REP(_, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    pall.resize(N);
    pm1.resize(N);
    dfs(0, -1);
    vall.resize(N);
    vm1.resize(N);
    vall[0] = 1;
    dfs2(0, -1);
    // dbg(pm1);
    // dbg(pall);
    // dbg(vm1);
    // dbg(vall);

    printf("%lld %d\n", pall[0], (int)ret.size());
    for (auto x : ret) printf("%d ", x + 1);
    puts("");
}