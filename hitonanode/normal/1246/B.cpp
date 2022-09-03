#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


vector<int> makePrimeLst(int N)
{
    vector<int> ans;
    vector<int> alive(N+1, 1);
    lint now = 2;
    for (; now * now <= N; now++)
    {
        if (alive[now]) ans.push_back(now);
        for (int t = now; t <= N; t += now) alive[t] = 0;
    }
    for (; now <= N; now++) if (alive[now]) ans.push_back(now);
    return ans;
}

// 
map<lint, int> primeFactorize(lint N, const vector<int> &primeLst)
{
    map<lint, int> ans;
    for (auto v : primeLst)
    {
        while (!(N % v))
        {
            N /= v;
            ans[v]++;
        }
        if (N == 1) return ans;
    }
    ans[N]++;
    return ans;
    // exit(1);
}

int main()
{
    vector<int> primes = makePrimeLst(400);
    int N, K;
    cin >> N >> K;
    map<lint, lint> cou;
    lint ret = 0;
    REP(i, N)
    {
        int a;
        cin >> a;
        map<lint, int> mp = primeFactorize(a, primes);
        int acc = 1, query = 1;
        for (auto p : mp)
        {
            REP(_, p.second % K) acc *= p.first;
            REP(_, (K - p.second % K) % K)
            {
                query *= p.first;
                if (query > 1000000)
                {
                    query = -1;
                    break;
                }
            }
        }
        ret += cou[query];
        cou[acc]++;
    }
    cout << ret << endl;
}