#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void zaatsu(vector<pint> &seg)
{
    vector<int> x(seg.size() * 2);
    REP(i, int(seg.size())) x[i * 2] = seg[i].first, x[i * 2 + 1] = seg[i].second;
    sort(ALL(x));
    x.erase(unique(ALL(x)), x.end());
    map<int, int> z;
    for (auto s : x) {
        int n = z.size();
        z[s] = n * 2;
    }
    for (auto &p : seg) p.first = z[p.first], p.second = z[p.second];
}

int solve(vector<pint> seg)
{
    int N = seg.size();
    zaatsu(seg);
    vector<int> acc(N * 4 + 7);
    for (auto p : seg) acc[p.first]++, acc[p.second + 1]--;
    REP(i, int(acc.size()) - 1) acc[i + 1] += acc[i];
    int ret = 1;
    FOR(i, 1, int(acc.size()) - 1) if (acc[i - 1] and !acc[i] and acc[i + 1]) ret++;
    
    vector<int> one(N * 4 + 7);
    REP(i, int(one.size())) one[i] = (acc[i] == 1);
    vector<int> oneacc = one;
    REP(i, oneacc.size()) if (i % 2 == 0) oneacc[i] = 0;
    REP(i, int(oneacc.size()) - 1) oneacc[i + 1] += oneacc[i];
    int ret_add = -1;
    for (auto p : seg) {
        if (p.first == p.second)
        {
            if (!one[p.first]) mmax(ret_add, 0);
        }
        else mmax(ret_add, oneacc[p.second] - oneacc[p.first] - (one[p.first] == 1) - (one[p.second] == 1));
    }
    return ret + ret_add;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<pint> seg(N);
        REP(i, N) cin >> seg[i].first >> seg[i].second;
        int ret = solve(seg);
        printf("%d\n", ret);
    }
}