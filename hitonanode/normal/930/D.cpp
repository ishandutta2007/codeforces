#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }


lint solve(vector<pint> v) {
    sort(v.begin(), v.end());
    map<int, vector<int>> x2y;
    for (auto p : v) x2y[p.first].push_back(p.second);
    set<pint> yx;
    for (auto p : v) yx.emplace(p.second, p.first);

    int lo = 1e9, hi = -1e9;
    lint ret = 0;
    REP(l, 425050) {
        int hinxt = hi;
        int lonxt = lo;
        if (x2y.count(l)) {
            for (auto y : x2y[l]) {
                yx.erase(pint(y, l));
                chmax(hinxt, y);
                chmin(lonxt, y);
            }
        }
        if (yx.empty()) break;
        int b = max(lo, yx.begin()->first);
        int e = min(hi, prev(yx.end())->first);
        if (b < e) {
            if (l % 2 == 0) ret += (e - b) / 2;
        }
        hi = hinxt;
        lo = lonxt;
    }
    return ret;
}

int main()
{
    int N;
    cin >> N;
    vector<pint> vo, ve;
    while (N--) {
        int x, y;
        cin >> x >> y;
        if ((x + y) % 2) vo.emplace_back(x + y + 202020, x - y);
        else ve.emplace_back(x + y - 1 + 202020, x - y - 1);
    }

    cout << solve(vo) + solve(ve) << "\n";
}