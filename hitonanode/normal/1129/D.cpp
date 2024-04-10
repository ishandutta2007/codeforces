#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx", "avx2")
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

constexpr int MOD = 998244353;
struct custom_hash
{
    // <https://codeforces.com/blog/entry/62393>
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct Node
{
    vector<pair<int, lint>> mpacc;
    vector<int> keys;
    vector<lint> vals;
    int bias;
    Node() : bias(0) {}

    void brange_add(int l, int r, int kadd)
    {
        FOR(i, l, r) keys[i] += kadd;
        build();
    }

    void build()
    {
        REP(i, keys.size()) keys[i] += bias;
        bias = 0;

        vector<pair<int, lint>> mp(keys.size());
        REP(i, keys.size())
        {
            mp[i] = make_pair(keys[i], vals[i]);
        }
        sort(mp.begin(), mp.end());
        mpacc.clear();
        mpacc.emplace_back(-1e9, 0);
        lint acc = 0;
        for (auto p : mp)
        {
            acc += p.second;
            if (p.first != mpacc.back().first) mpacc.emplace_back(p.first, acc);
            else mpacc.back().second = acc;
        }
    }
    void add_bias(int x)
    {
        bias += x;
    }
    lint get(int q)
    {
        auto itr = upper_bound(mpacc.begin(), mpacc.end(), pair<int, lint>(q - bias, 1e18));
        return prev(itr)->second % MOD;
    }
};

constexpr int B = 128;

vector<Node> nodes;

void add(int l, int r, int val)
{
    if ((r - 1) / B == l / B)
    {
        nodes[l / B].brange_add(l % B, (r % B ? r % B : B), val);
        return;
    }

    if (l % B)
    {
        nodes[l / B].brange_add(l % B, B, val);
    }
    if (r % B)
    {
        nodes[r / B].brange_add(0, r % B, val);
    }
    int x = (l + B - 1) / B;
    while (B * (x + 1) <= r)
    {
        nodes[x].add_bias(val);
        x++;
    }
}

int N, K;

int M;
lint get_sum(int q)
{
    lint ret = 0;
    REP(i, M) ret += nodes[i].get(q);
    return ret % MOD;
}

int main()
{
    cin >> N >> K;
    M = ((N + 1) + B - 1) / B;

    nodes.assign(M, Node());
    REP(i, M)
    {
        nodes[i].keys.assign(B, 0);
        nodes[i].vals.assign(B, 0);
    }

    nodes.at(0).vals.at(0) = 1;
    REP(i, M) nodes[i].build();


    unordered_map<int, vector<int>, custom_hash> pos;

    lint dpnow = 0;
    FOR(i, 1, N + 1)
    {
        int a;
        cin >> a;
        if (pos[a].size() >= 2)
        {
            int j = pos[a][pos[a].size() - 2];
            int k = pos[a][pos[a].size() - 1];
            add(j, k, -1);
            add(k, i, 1);
        }
        else if (pos[a].size() == 1)
        {
            int k = pos[a][pos[a].size() - 1];
            add(0, k, -1);
            add(k, i, 1);
        }
        else
        {
            add(0, i, 1);
        }
        pos[a].push_back(i);
        dpnow = get_sum(K);
        nodes[i / B].keys[i % B] = 0;
        nodes[i / B].vals[i % B] = dpnow;
        nodes[i / B].build();
    }
    cout << dpnow << endl;
}