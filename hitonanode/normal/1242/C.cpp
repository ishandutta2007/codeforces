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
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

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
void NO()
{
    puts("No");
    exit(0);
}


int K;
unordered_map<lint, int, custom_hash> a2loc;
vector<lint> diff;

vector<lint> gen_seq(lint a)
{
    vector<lint> ret{a};
    vector<int> visited(K);
    lint ainit = a;
    int pos = a2loc[a];
    visited[pos] = 1;
    
    while (true)
    {
        lint vnxt = diff[pos] + a;
        if (vnxt == ainit) return ret;
        if (!a2loc.count(vnxt)) return vector<lint>{};
        int nxtpos = a2loc[vnxt];
        if (visited[nxtpos]) return vector<lint>{};
        visited[nxtpos] = 1;
        pos = nxtpos;
        a = vnxt;
        ret.push_back(a);
    }
}

int main()
{
    cin >> K;
    vector<vector<lint>> A(K);
    vector<lint> Asum(K);
    REP(k, K)
    {
        int N;
        cin >> N;
        A[k].resize(N);
        cin >> A[k];
        REP(i, N) a2loc[A[k][i]] = k;
        Asum[k] = accumulate(A[k].begin(), A[k].end(), 0LL);
    }
    lint tot = accumulate(Asum.begin(), Asum.end(), 0LL);
    if (tot % K) NO();
    lint goal = tot / K;
    // dbg(A);

    diff.resize(K);
    REP(i, K) diff[i] = -Asum[i] + goal;

    vector<vector<lint>> S(1 << K);
    REP(k, K)
    {
        for (auto a : A[k])
        {
            vector<lint> seq = gen_seq(a);
            if (seq.empty()) continue;
            int se = 0;
            for (auto v : seq) se += 1 << (a2loc[v]);
            S[se] = seq;
        }
    }
    vector<int> dp(1 << K, -1);
    REP(s, 1 << K) if (S[s].size()) dp[s] = s;
    REP(s, 1 << K)
    {
        for (int t = (s - 1) & s; t > 0; t = (t - 1) & s)
        {
            if (dp[t] >= 0 and dp[t ^ s] >= 0) dp[s] = t;
        }
    }
    if (dp.back() >= 0)
    {
        cout << "Yes" << endl;
        int s = (1 << K) - 1;
        set<int> as;
        while (s)
        {
            int t = dp[s];
            for (auto v : S[t]) as.insert(v);
            s ^= t;
        }
        vector<pint> ret(K);
        for (auto a : as)
        {
            int p = a2loc[a];
            lint nx = a + diff[p];
            ret[a2loc[nx]] = make_pair(nx, p);
        }
        REP(i, K) cout << ret[i].first << " " << ret[i].second + 1 << endl;
    }
    else
    {
        NO();
    }
}