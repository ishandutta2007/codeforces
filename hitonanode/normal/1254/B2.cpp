#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

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
}

int main()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    lint tot = accumulate(ALL(A), 0LL);
    vector<int> primes = makePrimeLst(1000000);
    map<lint, int> ya = primeFactorize(tot, primes);


    ya.erase(1);

    lint ret = -1;
    for (auto p : ya)
    {
        lint m = p.first;
        lint cost = 0;
        lint nokori = 0;
        REP(i, N)
        {
            nokori = (nokori + A[i]) % m;
            cost += min(nokori, m - nokori);
        }
        if (ret < 0 or ret > cost) ret = cost;
    }
    cout << ret << endl;
}