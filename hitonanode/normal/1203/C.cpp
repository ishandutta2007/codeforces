#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


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
    // exit(1);
}
vector<lint> divisor(lint n, const vector<int> &primeLst)
{
    map<lint, int> factor = primeFactorize(n, primeLst);
    vector<lint> now{1}, nxt;
    for (auto pa : factor)
    {
        nxt.clear();
        for (auto v : now)
        {
            REP(i, pa.second + 1)
            {
                nxt.push_back(v);
                v *= pa.first;
            }
        }
        swap(now, nxt);
    }
    return now;
}

int main()
{
    vector<int> primes = makePrimeLst(1000000);
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    lint g = A[0];
    for (auto v : A) g = __gcd(g, v);
    cout << divisor(g, primes).size() << endl;
}