#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

vector<int> B;
lint solve(lint now, lint nxt)
{
    lint h1 = *lower_bound(ALL(B), now);
    lint h2 = *prev(lower_bound(ALL(B), now));

    lint ret1 = abs(h1 - now) + abs(nxt - h1);
    lint ret2 = abs(h2 - now) + abs(nxt - h2);
    return min(ret1, ret2);
}

int main()
{
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    map<int, vector<int>> ts;
    REP(_, K)
    {
        int r, c;
        cin >> r >> c;
        ts[r].push_back(c);
    }
    B.resize(Q);
    cin >> B;
    B.push_back(-1e6);
    B.push_back(1e6);
    sort(ALL(B));
    lint pl = 1, pr = 1, dpl = 0, dpr = 0, c = 1;
    
    for (auto t : ts)
    {
        int lo = *min_element(ALL(t.second)), hi = *max_element(ALL(t.second));
        if (t.first == 1)
        {
            pl = pr = hi;
            dpl = dpr = hi - 1;
            continue;
        }
        dpl += t.first - c;
        dpr += t.first - c;
        c = t.first;

        lint dpl_new = min(dpl + solve(pl, hi), dpr + solve(pr, hi)) + (hi - lo);
        lint dpr_new = min(dpl + solve(pl, lo), dpr + solve(pr, lo)) + (hi - lo);

        dpl = dpl_new;
        dpr = dpr_new;
        pl = lo;
        pr = hi;
    }
    cout << min(dpl, dpr) << endl;
}