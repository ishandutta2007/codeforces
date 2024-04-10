#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int H;
    cin >> H;
    vector<int> A(H + 1);
    cin >> A;
    bool perf = true;
    REP(i, A.size() - 1) if (A[i] > 1 and A[i + 1] > 1)
    {
        perf = false;
    }
    if (perf)
    {
        puts("perfect");
        return 0;
    }

    vector<int> ret1, ret2;
    int prv = 0;
    REP(i, A.size())
    {
        REP(t, A[i])
        {
            ret1.emplace_back(prv);
            ret2.emplace_back((t and i and A[i - 1] > 1) ? prv - 1 : prv);
        }
        prv += A[i];
    }

    puts("ambiguous");
    for (auto x : ret1) printf("%d ", x);
    puts("");
    for (auto x : ret2) printf("%d ", x);
    puts("");
}