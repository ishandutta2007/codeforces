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

int root;
vector<set<int>> e;
vector<int> par, d, subtreesz, max_sep_size;

void dfs_distance_from_root(int now, int prv)
{
    for (auto nxt : e[now]) if (nxt != prv)
    {
        par[nxt] = now;
        d[nxt] = d[now] + 1;
        dfs_distance_from_root(nxt, now);
    }
}

int dfs1(int now, int prv)
{
    subtreesz[now] = 1;
    for (auto nxt : e[now]) if (nxt != prv)
    {
        subtreesz[now] += dfs1(nxt, now);
    }
    return subtreesz[now];
}

int dfs2(int now, int prv)
{
    vector<int> stsz{subtreesz[root] - subtreesz[now]};
    for (auto nxt : e[now]) if (nxt != prv) stsz.push_back(dfs2(nxt, now));
    max_sep_size[now] = *max_element(ALL(stsz));
    return subtreesz[now];
}


void answer(int i)
{
    cout << "! " << i << endl;
    exit(0);
}

int main()
{
    int N;
    cin >> N;
    e.resize(N + 1);
    par.resize(N + 1);
    d.resize(N + 1);
    subtreesz.resize(N + 1);
    root = 1;
    REP(_, N - 1)
    {
        int a, b;
        cin >> a >> b;
        e[a].insert(b);
        e[b].insert(a);
    }
    
    par[root] = -1;
    d[root] = 0;
    dfs_distance_from_root(root, 0);
    // dbg(par);

    cout << "d 1" << endl;
    int d_from_1;
    cin >> d_from_1;
    if (d_from_1 == 0) answer(1);

    while (e[root].size())
    {
        // dbg(root);
        // dbg(e[root]);
        // dbg(par);
        dfs1(root, -1);
        max_sep_size.assign(N + 1, N);
        dfs2(root, -1);
        int i = distance(max_sep_size.begin(), min_element(ALL(max_sep_size)));
        cout << "d " << i << endl;
        cout.flush();
        int resp;
        cin >> resp;
        if (resp == 0) answer(i);
        else if (resp + d[i] == d_from_1)
        {
            cout << "s " << i << endl;
            cout.flush();
            cin >> root;
            e[root].erase(par[root]);
            e[par[root]].erase(root);
        }
        else
        {
            // i;
            int j = par[i];
            e[i].erase(j);
            e[j].erase(i);
        }
    }
    answer(root);
}