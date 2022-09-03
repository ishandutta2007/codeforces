#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_by_key()
template<typename TK> using pb_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pb_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;



int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> cou(M + 1);
    REP(_, N)
    {
        int a;
        cin >> a;
        cou[a]++;
    }

    map<int, vector<int>> ma;
    FOR(m, 1, M + 1) ma[cou[m]].emplace_back(m);

    vector<lint> query(Q), query_sorted;
    cin >> query;
    query_sorted = query;
    sort(ALL(query_sorted));

    int solved_query = 0;
    map<lint, lint> q2ans;

    lint now = N, hprv = 0;
    pb_set<int> fcity;
    for (auto pa : ma)
    {
        lint hdiff = pa.first - hprv;

        lint date_add = fcity.size() * hdiff;
        while (solved_query < Q and query_sorted[solved_query] > now and query_sorted[solved_query] <= now + date_add)
        {
            lint q = query_sorted[solved_query];
            lint x = (q - now - 1) % fcity.size();
            q2ans[q] = *fcity.find_by_order(x);
            solved_query++;
        }

        now += date_add;
        hprv = pa.first;
        for (auto m : pa.second) fcity.insert(m);
    }

    while (solved_query < Q)
    {
        lint q = query_sorted[solved_query];
        lint x = (q - now - 1) % fcity.size();
        q2ans[q] = *fcity.find_by_order(x);
        solved_query++;
    }
    for (auto v : query)
    {
        printf("%lld\n", q2ans[v]);
    }
}