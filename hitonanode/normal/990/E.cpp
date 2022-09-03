#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> OK(N + 1, 1);
    while (M--) {
        int s;
        cin >> s;
        OK[s] = 0;
    }
    if (!OK[0]) {
        puts("-1");
        return 0;
    }
    vector<int> prv(N + 1);
    int l = -1;
    REP(i, N + 1) {
        if (OK[i]) l = i;
        prv[i] = l;
    }
    lint ret = 1e14;
    vector<lint> A(K);
    cin >> A;
    REP(i, K) {
        int d = i + 1;
        lint n = 0;
        int now = 0;
        bool flg = true;
        while (now < N) {
            int tx = min(now + d, N);
            int nxt = prv[tx];
            if (nxt == now) {
                flg = false;
                break;
            }
            now = nxt;
            n++;
        }
        if (flg) chmin(ret, A[i] * n);
    }
    if (ret < 1e14) cout << ret << "\n";
    else puts("-1");
}