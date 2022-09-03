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



set<int> makePrimeLst(int N)
{
    set<int> ans;
    vector<int> alive(N+1, 1);
    lint now = 2;
    for (; now * now <= N; now++)
    {
        if (alive[now]) ans.insert(now);
        for (int t = now; t <= N; t += now) alive[t] = 0;
    }
    for (; now <= N; now++) if (alive[now]) ans.insert(now);
    return ans;
}

void solve(int N)
{
    set<int> primes = makePrimeLst(N * 2);

    int M = N;
    while(!primes.count(M)) M++;
    if (M > N + N / 2) exit(8);
    printf("%d\n", M);
    REP(i, N) printf("%d %d\n", i % N + 1, (i + 1) % N + 1);
    REP(i, M - N) printf("%d %d\n", i % N + 1, (N / 2 + i) % N + 1);
}

int main()
{
    int N;
    cin >> N;
    solve(N);
}