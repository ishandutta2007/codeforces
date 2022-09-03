#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


constexpr int INF = 3e8;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, pint>> lr;
    while (M--)
    {
        int d, h;
        cin >> d >> h;
        lr.emplace_back(d, pint(h, h));
    }
    if (lr[0].first != 1)
    {
        lr.insert(lr.begin(), make_pair(1, pint(0, INF)));
    }
    if (lr.back().first != N)
    {
        lr.emplace_back(N, pint(0, INF));
    }
    FOR(i, 1, lr.size())
    {
        int dt = lr[i].first - lr[i - 1].first;
        chmax(lr[i].second.first, lr[i - 1].second.first - dt);
        chmin(lr[i].second.second, lr[i - 1].second.second + dt);
    }
    IREP(i, lr.size() - 1)
    {
        int dt = lr[i + 1].first - lr[i].first;
        chmax(lr[i].second.first, lr[i + 1].second.first - dt);
        chmin(lr[i].second.second, lr[i + 1].second.second + dt);
    }

    REP(i, lr.size()) if (lr[i].second.second < lr[i].second.first)
    {
        puts("IMPOSSIBLE");
        return 0;
    }

    int ret = 0;
    for (auto p : lr) chmax(ret, p.second.second);
    REP(i, lr.size() - 1)
    {
        int hl = lr[i].second.second, hr = lr[i + 1].second.second, dt = lr[i + 1].first - lr[i].first;
        chmax(ret, (hl + hr + dt) / 2);
    }
    cout << ret << '\n';
}