#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

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

struct rand_int_
{
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;


struct SegTree
{
    using T = lint;
    int N;
    int head;
    vector<T> x;
    T defaultT;
    T _get(int begin, int end, int pos, int l, int r) const
    {
        if (r <= begin or l >= end) return defaultT;
        if (l >= begin and r <= end) return x[pos];
        return _get(begin, end, 2 * pos + 1, l, (l + r) / 2) ^ _get(begin, end, 2 * pos + 2, (l + r) / 2, r);
    }
    SegTree(int N, T defaultT) : N(N), defaultT(defaultT)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
    }
    SegTree(const vector<T> &vals, T defaultT) : N(vals.size()), defaultT(defaultT)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
        copy(vals.begin(), vals.end(), x.begin() + head);
        IREP(i, head) x[i] = x[i * 2 + 1] ^ x[i * 2 + 2];
    }
    void build(const vector<T> &vals) { copy(vals.begin(), vals.end(), x.begin() + head); IREP(i, head) x[i] = x[i * 2 + 1] ^ x[i * 2 + 2]; }
    void update(int pos, T val) { pos += head, x[pos] ^= val; while (pos) pos = (pos - 1) / 2, x[pos] = x[pos*2+1] ^ x[pos*2+2]; }
    T get(int begin, int end) const { return _get(begin, end, 0, 0, (int)x.size() / 2); }
    // friend ostream &operator<<(ostream &os, const SegTree &s) { os << "["; REP(i, s.N) os << s.get(i, i + 1) << ","; os << "]"; return os; }
};


vector<pint> zaatsu(vector<int> s, vector<int> e) {
    int N = s.size();
    set<int> visited;
    for (auto x : s) visited.insert(x);
    for (auto x : e) visited.insert(x);
    unordered_map<int, int, custom_hash> mp;
    for (auto x : visited) {
        int n = mp.size();
        mp[x] = n;
    }
    vector<pint> ret(N);
    REP(i, N) ret[i] = make_pair(mp[s[i]], mp[e[i]]);
    return ret;
}


vector<lint> solve(vector<pint> ps, const vector<lint> &vh) {
    int N = ps.size();
    vector<lint> x(N * 2 + 1);
    REP(i, N) x[ps[i].first] ^= vh[i];
    SegTree st(x, 0);
    REP(i, N) x[ps[i].second + 1] ^= vh[i];
    vector<lint> xacc = x;
    REP(i, N * 2) xacc[i + 1] = xacc[i] ^ x[i + 1];

    vector<lint> ret(N);
    REP(i, N) {
        int l = ps[i].first, r = ps[i].second;
        ret[i] = xacc[l] ^ st.get(l + 1, r + 1);
    }
    return ret;
}

int main()
{
    int N;
    cin >> N;

    vector<int> sa(N), ea(N), sb(N), eb(N);
    REP(i, N) {
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }
    vector<pint> pa = zaatsu(sa, ea);
    vector<pint> pb = zaatsu(sb, eb);
    vector<lint> vh;
    vector<lint> wh;
    vh.resize(N);
    wh.resize(N);

    REP(i, N) {
        vh[i] = rnd(9e18);
        wh[i] = rnd(9e18);
    }
    auto r1v = solve(pa, vh);
    auto r2v = solve(pb, vh);
    auto r1w = solve(pb, wh);
    auto r2w = solve(pb, wh);
    cout << (r1v == r2v and r1w == r2w ? "YES" : "NO") << endl;
}