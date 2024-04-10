#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    lint N, X;
    cin >> N >> X;
    vector<lint> D(N);
    cin >> D;
    D.resize(N * 3);
    REP(i, N * 2) D[i + N] = D[i];
    lint ret = 0;

    lint len = 0;
    lint tmp = 0;
    int l = 0, r = 0;
    while (r < N * 3)
    {
        if (len <= X)
        {
            chmax(ret, tmp);
        }
        if (len < X)
        {
            tmp += D[r] * (D[r] + 1) / 2;
            len += D[r];
            r++;
            continue;
        }
        if (len <= X)
        {
            chmax(ret, tmp);
        }
        if (len >= X)
        {
            lint diff = len - X;
            chmax(ret, tmp - diff * (diff + 1) / 2);
            tmp -= D[l] * (D[l] + 1) / 2;
            len -= D[l];
            l++;
        }
    }
    cout << ret << '\n';
}