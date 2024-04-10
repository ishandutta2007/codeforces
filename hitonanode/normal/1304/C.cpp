#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }

bool solve()
{
    int N, M;
    cin >> N >> M;
    map<int, pint> mp;
    while (N--) {
        int t, l, h;
        cin >> t >> l >> h;
        if (mp.count(t)) {
            mmax(mp[t].first, l);
            mmin(mp[t].second, h);
        }
        else mp[t] = make_pair(l, h);
    }
    int now = 0;
    int tlo = M, thi = M;
    for (auto p : mp) {
        tlo -= p.first - now, thi += p.first - now;
        now = p.first;
        if (thi < p.second.first or p.second.second < tlo) return false;
        mmax(tlo, p.second.first);
        mmin(thi, p.second.second);
        if (tlo > thi) return false;
    }
    return true;
}

signed main()
{
    int Q;
    cin >> Q;
    while (Q--) cout << (solve() ? "YES" : "NO") << endl;
}