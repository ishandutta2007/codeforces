#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }


int main()
{
    vector<int> N(3);
    cin >> N;
    vector<lint> tot(3);
    vector<lint> mi(3, 1LL << 30);
    REP(i, 3) {
        REP(_, N[i]) {
            lint a;
            cin >> a;
            tot[i] += a;
            chmin(mi[i], a);
        }
    }
    sort(tot.begin(), tot.end());
    sort(mi.begin(), mi.end());
    cout << accumulate(tot.begin(), tot.end(), 0LL) - min(tot[0], mi[0] + mi[1]) * 2 << '\n';
}