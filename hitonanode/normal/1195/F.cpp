#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;


constexpr lint DMAX = 2000000010;
lint gen(lint dx, lint dy)
{
    if (!dx and !dy) return 0;
    if (!dx) return dy / abs(dy);
    if (!dy) return dx / abs(dx) * DMAX;
    lint g = __gcd(abs(dx), abs(dy));
    return dx / g * DMAX + dy / g;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> L(N);
    vector<int> nx_pos;

    {
        vector<lint> g;
        REP(i, N)
        {
            int K;
            cin >> K;
            L[i] = g.size();
            vector<lint> x(K), y(K);
            REP(j, K) cin >> x[j] >> y[j];
            REP(j, K) g.push_back(gen(x[(j + 1) % K] - x[j], y[(j + 1) % K] - y[j]));
        }
        L.push_back(g.size());

        nx_pos.assign(g.size(), 1e9);
        map<lint, int> ma;
        IREP(i, g.size())
        {
            if (ma.count(g[i])) nx_pos[i] = ma[g[i]];
            ma[g[i]] = i;
        }
    }

    int B = 5000, S = (nx_pos.size() + B - 1) / B;
    vector<int> sq = nx_pos;
    sq.resize(B * S, 1e9);
    REP(i, S) sort(sq.begin() + i * B, sq.begin() + (i + 1) * B);

    int Q;
    cin >> Q;
    REP(_, Q)
    {
        int l, r;
        cin >> l >> r;
        l = L[l - 1], r = L[r];
        int ret = r - l;
        if (r - l < B * 2) FOR(i, l, r) ret -= (nx_pos[i] < r);
        else
        {
            FOR(n, (l + B - 1) / B, r / B) ret -= distance(sq.begin() + n * B, lower_bound(sq.begin() + n * B, sq.begin() + (n + 1) * B, r));
            FOR(i, l, (l + B - 1) / B * B) ret -= (nx_pos[i] < r);
            FOR(i, r / B * B, r) ret -= (nx_pos[i] < r);
        }
        printf("%d\n", ret);
    }
}