#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;


int main()
{
    int N;
    cin >> N;
    vector<pint> A(N);
    REP(i, N)
    {
        int a;
        cin >> a;
        A[i] = make_pair(-a, i);
    }
    sort(ALL(A));

    pbds_set<pint> ps;

    int M;
    cin >> M;
    vector<vector<pint>> K2IDP(200001);
    REP(i, M)
    {
        int k, p;
        cin >> k >> p;
        K2IDP[k].emplace_back(i, p - 1);
    }
    vector<int> ret(M);
    for (auto a : A)
    {
        ps.insert(pint(a.second, -a.first));
        for (auto id_p : K2IDP[ps.size()])
        {
            ret[id_p.first] = ps.find_by_order(id_p.second)->second;
        }
    }
    for (auto v : ret) printf("%d\n", v);
}