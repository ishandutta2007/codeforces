#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int N;
vector<lint> A;
set<lint> used;

vector<vector<int>> e;
constexpr lint INF = 1e17;

constexpr lint INVALID = INF * 2;

vector<int> C;

void add_val(int now, lint lo, lint hi) {
    lint v = A[lo] + (A[hi] - A[lo]) / 2;
    if (lo == N and hi == N + 1) {
        v = now * 10000;
    }
    else if (used.count(v)) {
        map<lint, int> z;
        for (auto a : used) {
            int n = z.size();
            z[a] = n;
        }
        REP(i, N) {
            if (A[i] != INVALID) A[i] = -INF + INF * 2 / (z.size() + 5) * (z[A[i]] + 2);
        }

        used.clear();
        for (auto a : A) if (a != INVALID) used.insert(a);

        v = A[lo] + (A[hi] - A[lo]) / 2;
    }

    while (used.count(v)) v++;

    A[now] = v;
    used.insert(v);
}

vector<int> dfs(int now) {
    vector<int> tmp;
    for (auto nxt : e[now]) {
        vector<int> t = dfs(nxt);
        tmp.insert(tmp.end(), ALL(t));
    }
    sort(ALL(tmp), [](int l, int r) { return A[l] < A[r]; });

    if (C[now] > tmp.size()) {
        puts("NO");
        exit(0);
    }
    else if (tmp.empty())
    {
        add_val(now, N, N + 1);
    }
    else if (C[now] == tmp.size())
    {
        add_val(now, tmp.back(), N + 1);
    }
    else if (C[now] == 0) {
        add_val(now, N, tmp[0]);
    }
    else {
        add_val(now, tmp[C[now] - 1], tmp[C[now]]);
    }

    tmp.push_back(now);
    return tmp;
}

int main()
{
    cin >> N;
    int root = -1;
    A.assign(N, INVALID);
    A.push_back(-INF);
    A.push_back(INF);
    e.resize(N);
    C.resize(N);

    REP(i, N)
    {
        int par;
        cin >> par >> C[i];
        par--;
        if (par < 0) root = i;
        else e[par].push_back(i);
    }

    dfs(root);

    map<lint, int> mp;
    for (auto a : A) used.insert(a);
    for (auto x : used) {
        int n = mp.size() + 1;
        mp[x] = n;
    }

    puts("YES");
    REP(i, N)
    {
        printf("%d ", mp[A[i]]);
    }
    puts("");
}