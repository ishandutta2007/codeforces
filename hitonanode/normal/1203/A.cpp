#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////



int main()
{
    int Q;
    cin >> Q;
    REP(_, Q)
    {
        int N;
        cin >> N;
        vector<int> P(N);
        cin >> P;
        bool flg = true;
        REP(i, N) {
            if (P[i] == N and P[(i + 1) % N] == 1) continue;
            if (P[i] == 1 and P[(i + 1) % N] == N) continue;
            if (abs(P[i] - P[(i + 1) % N]) != 1) flg = false;
        }
        if (flg) puts("YES"); else puts("NO");
    }
}