#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


int main()
{
    lint N, K, M, D;
    cin >> N >> K >> M >> D;
    lint ret = 0;
    REP(d, D)
    {
        __int128 ts = __int128(K) * d + 1;
        __int128 unit = min<__int128>(N / ts, M);
        if (!unit) continue;
        __int128 tt = N / unit;
        if (tt > __int128(K) * D or !tt) continue;
        chmax<lint>(ret, (tt + K - 1) / K * unit);
    }
    cout << ret << "\n";
}