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


int main()
{
    string S;
    cin >> S;
    int v_len = 0;
    vector<lint> vs;
    for (auto c : S)
    {
        if (c == 'v') v_len++;
        else
        {
            vs.push_back(v_len);
            v_len = 0;
        }
    }
    vs.push_back(v_len);
    int N = vs.size();
    vector<lint> a(N + 1);
    REP(i, N) a[i + 1] = a[i] + max(vs[i] - 1, 0LL);
    lint ret = 0;
    REP(i, N) ret += (a[N] - a[i]) * a[i];
    cout << ret << endl;
}