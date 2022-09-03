#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    lint N, C, D;
    cin >> N >> C >> D;
    vector<pair<lint, char>> V(N);
    REP(i, N)
    {
        cin >> V[i].first >> V[i].second;
    }
    lint LastP, LastW;
    cin >> LastP;
    LastW = LastP;
    lint ret = N * D;

    lint acccost = 0;
    bool last = false;

    lint step = 0;
    IREP(i, N)
    {
        if (last and V[i].second != V[i + 1].second)
        {
            acccost += step * C - D;
        }
        last = false;

        if (V[i].second == 'P')
        {
            lint lc = C * (LastW - V[i].first);
            step = LastW - V[i].first;
            if (lc > D) last = true;
            acccost += min(D, lc);
            LastP = V[i].first;
        }
        else
        {
            lint lc = C * (LastP - V[i].first);
            step = LastP - V[i].first;
            if (lc > D) last = true;
            acccost += min(D, lc);
            LastW = V[i].first;
        }
        // dbg(i);
        // dbg(acccost);
        mmin(ret, i * D + acccost);
    }
    cout << ret << endl;
}