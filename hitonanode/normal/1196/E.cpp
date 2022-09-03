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

void solve(int N, int m, int a, int b)
{
    if (N > m * 3 + 1) puts("NO");
    else
    {
        set<pint> ret;
        while (m)
        {
            ret.emplace(a, b);
            m--;
            vector<pint> ts{{a, b + 1}, {a, b - 1}, {a + 1, b}, {a - 1, b}};
            for (auto t : ts)
            {
                if (N <= m) break;
                if (!ret.count(t)) ret.emplace(t), N--;
            }
            b += 2;
        }
        puts("YES");
        for (auto pa : ret) printf("%d %d\n", pa.first, pa.second);
    }
}

int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        int B, W;
        cin >> B >> W;
        if (B > W) solve(B, W, 3, 3);
        else solve(W, B, 4, 3);
    }
}