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


constexpr lint MOD = 1000000007;

lint dp(int l)
{
    vector<int> v(l + 1, 1);
    FOR(i, 1, l) v[i + 1] = (v[i] + v[i - 1]) % MOD;
    return v[l];
}

int main()
{
    string S;
    cin >> S;
    S += '_';
    lint ret = 1;
    int suc = 1;
    REP(i, S.length() - 1)
    {
        if (S[i] == S[i + 1]) suc++;
        else
        {
            if (S[i] == 'm') ret = 0;
            if (S[i] == 'w') ret = 0;
            if (S[i] == 'u' or S[i] == 'n') ret = ret * dp(suc) % MOD;
            suc = 1;
        }
    }
    cout << ret << endl;
}