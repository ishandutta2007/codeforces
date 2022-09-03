#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

int main()
{
    int N;
    string S, T;
    cin >> N >> S >> T;

    int hi = 0, lo = 0, cur = 0;
    REP(i, N)
    {
        cur = cur + S[i] - T[i];
        chmax(hi, cur);
        chmin(lo, cur);
    }
    cout << (cur ? -1 : hi - lo) << '\n';
}