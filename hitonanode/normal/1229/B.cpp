#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

constexpr lint MOD = 1000000007;

vector<set<int>> e;

vector<lint> X;
vector<lint> chnum, gcdtmp;
lint ret;
lint Gcd(lint a, lint b)
{
    if (a == 0 and b == 0) return 0;
    if (a == 0 or b == 0) return a + b;
    return __gcd(a, b);
}

void dfs(int now, int prv, map<lint, int> gcd2c)
{
    for (auto p : gcd2c) (ret += Gcd(p.first, X[now]) % MOD * p.second) %= MOD;
    map<lint, int> manew;
    (ret += X[now]) %= MOD;
    manew[X[now]]++;
    for (auto p : gcd2c) manew[Gcd(p.first, X[now])] += p.second;
    for (auto nxt : e[now]) if (nxt != prv)
    {
        dfs(nxt, now, manew);
    }
}

int main()
{
    int N;
    cin >> N;
    X.resize(N);
    cin >> X;
    e.resize(N);
    REP(_, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a].insert(b);
        e[b].insert(a);
    }
    chnum.resize(N), gcdtmp.resize(N);
    map<lint, int> m;
    dfs(0, -1, m);
    cout << ret % MOD << endl;
}