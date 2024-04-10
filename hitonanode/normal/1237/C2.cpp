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
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds; // find_by_order(), order_of_key()
template<typename TK> using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename TK, typename TV> using pbds_map = tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
*/

void out(int a, int b)
{
    printf("%d %d\n", a, b);
}

map<int, map<pint, int>> x2yz_i;

set<int> xs;
void solve_x(int x)
{
    map<int, vector<int>> y2zs;
    set<int> ys;

    for (auto p : x2yz_i[x])
    {
        ys.insert(p.first.first);
        y2zs[p.first.first].push_back(p.first.second);
    }
    for (auto y : ys)
    {
        vector<int> zs = y2zs[y];
        REP(i, zs.size() / 2)
        {
            out(x2yz_i[x][pint(y, zs[i * 2])], x2yz_i[x][pint(y, zs[i * 2 + 1])]);
        }
        if (zs.size() % 2)
        {
            int z = zs.back();
            auto itr = ys.upper_bound(y);
            if (itr == ys.end())
            {
                int nxtx = *xs.upper_bound(x);
                int Dmin = 1e9;
                pint nxtyz;
                for (auto yz_i : x2yz_i[nxtx])
                {
                    if (mmin(Dmin, abs(y - yz_i.first.first) + abs(z - yz_i.first.second)))
                    {
                        nxtyz = yz_i.first;
                    }
                }
                out(x2yz_i[x][pint(y, z)], x2yz_i[nxtx][nxtyz]);
                x2yz_i[nxtx].erase(nxtyz);
                if (x2yz_i[nxtx].empty()) x2yz_i[nxtx].clear();
            }
            else
            {
                int nxty = *itr;
                int Dmin = 1e9;
                int nxtz;
                for (auto zcand : y2zs[nxty])
                {
                    if (mmin(Dmin, abs(z - zcand))) nxtz = zcand;
                }
                out(x2yz_i[x][pint(y, z)], x2yz_i[x][pint(nxty, nxtz)]);
                x2yz_i[x].erase(pint(nxty, nxtz));
                y2zs[nxty].erase(lower_bound(ALL(y2zs[nxty]), nxtz));
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x2yz_i[x][pint(y, z)] = i + 1;
        xs.insert(x);
    }
    for (auto x : xs) solve_x(x);
}