#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;

// 1-indexed BIT (i : [1, len])
template<typename T>
struct BIT
{
    int len;
    vector<T> val;
    BIT(int num) : len(num), val(num + 1) {}
    BIT() : BIT(0) {}
    void reset() { fill(val.begin(), val.end(), 0); }
    void add(int pos, T v) { while (pos > 0 and pos <= len) val[pos] += v, pos += pos & -pos; }
    T sum(int pos) const // (0, pos]
    {
        T res = 0;
        while (pos > 0) res += val[pos], pos -= pos & -pos;
        return res;
    }
};
template<typename T> ostream &operator<<(ostream &os, const BIT<T> &b){ T prv = 0; os << "["; REP(i, b.len) { T nxt = b.sum(i + 1); os << nxt - prv << ","; prv = nxt; } os << "]"; return os; }


int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    cin >> P;
    vector<int> pi(N + 1);
    REP(i, N) pi[P[i]] = i + 1;

    BIT<int> trans(N);
    BIT<int> bit(N);
    FOR(i, 1, N + 1) bit.add(i, 1);

    long long int rett = 0;
    pbds_set<int> vis;
    FOR(i, 1, N + 1)
    {
        int pos = pi[i];
        trans.add(pos, 1);


        {
            int t = vis.order_of_key(pos);
            rett -= min(t, (int)vis.size() - t);
            bit.add(pos, -1);
        }

        if (vis.size()) {
            int n = vis.size();
            if (n % 2) {
                int th = *vis.find_by_order(n / 2);
                rett += abs(bit.sum(pos) - bit.sum(th));
            }
            else
            {
                int a = *vis.find_by_order(n / 2 - 1), b = *vis.find_by_order(n / 2);
                if (pos < a) rett += bit.sum(a) - bit.sum(pos);
                if (b < pos) rett += bit.sum(pos) - bit.sum(b);
            }
        }
        vis.insert(pos);

        int n = trans.sum(pos);
        rett += i - n;

        printf("%lld ", rett);
    }
    puts("");
}