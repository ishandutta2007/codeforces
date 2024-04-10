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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;

lint N;

int main()
{
    cin >> N;
    map<lint, vector<lint>> y2x;
    lint ret = 0;
    REP(_, N)
    {
        lint X, Y;
        cin >> X >> Y;
        y2x[-Y].push_back(X);
    }

    pbds_set<lint> x_shown;
    for (auto pa : y2x)
    {
        vector<lint> vec = pa.second;
        sort(vec.begin(), vec.end());
        for (auto v : vec) x_shown.insert(v);
        lint sz = x_shown.size();
        ret += sz * (sz + 1) / 2;

        vector<int> pos{-1};
        for (auto v : vec) pos.push_back((int)x_shown.order_of_key(v));
        pos.push_back(x_shown.size());
        REP(i, pos.size() - 1)
        {
            lint diff = pos[i + 1] - pos[i] - 1;
            ret -= diff * (diff + 1) / 2;
        }
    }
    cout << ret << endl;
}