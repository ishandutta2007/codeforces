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
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

void solve()
{
    int N;
    cin >> N;
    int r, p, s;
    cin >> r >> p >> s;
    string S;
    cin >> S;
    string ret;
    int win = 0;
    REP(i, N)
    {
        if (S[i] == 'R' and p) ret += 'P', p--;
        if (S[i] == 'P' and s) ret += 'S', s--;
        if (S[i] == 'S' and r) ret += 'R', r--;
        
        if ((int)ret.length() <= i) ret += '_';
        else win++;
    }
    if (win < (N + 1) / 2) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        REP(i, N) if (ret[i] == '_')
        {
            if (p) p--, ret[i] = 'P';
            else if (r) r--, ret[i] = 'R';
            else if (s) s--, ret[i] = 'S';
        }
        cout << ret << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}