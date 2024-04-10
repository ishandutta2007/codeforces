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


vector<int> solve_try(const string &s, int d)
{
    // 0~d d~9
    int l1 = 0, l2 = d;
    int N = s.length();
    vector<int> ret(N);
    REP(i, N)
    {
        int x = s[i] - '0';
        if (x > d or (x == d and l2 == d))
        {
            if (x < l2) return vector<int>{-1};
            else l2 = x, ret[i] = 2;
        }
        else
        {
            if (x < l1) return vector<int>{-1};
            else l1 = x, ret[i] = 1;
        }
    }
    return ret;
}

int main()
{
    int TC;
    cin >> TC;
    REP(_, TC)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;
        bool flg = false;
        REP(d, 10)
        {
            auto ret = solve_try(S, d);
            if (ret[0] != -1)
            {
                flg = true;
                for (auto v : ret) printf("%d", v);
                puts("");
                break;
            }
        }
        if (!flg) puts("-");
    }
}