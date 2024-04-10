#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }

vector<plint> pdd;

constexpr double PI = 3.141592653589793238;

struct P
{
    double theta;
    lint x, y;
    P() {}
    P(double theta, lint x, lint y) : theta(theta), x(x), y(y) {}
    bool operator<(const P &r) const {
        if (abs(theta - r.theta) > 0.1) {
            return theta < r.theta;
        }
        lint tmp = x * r.y - y * r.x;
        return tmp > 0;
    }
};

lint solve_bad(int k)
{
    vector<P> ps;
    REP(i, pdd.size()) if (i != k) {
        double d = atan2(pdd[i].second - pdd[k].second, pdd[i].first - pdd[k].first);
        // ps.emplace_back(d, pdd[i] - pdd[k]);
        ps.emplace_back(d, pdd[i].first - pdd[k].first, pdd[i].second - pdd[k].second);
    }
    sort(ALL(ps));

    int K = ps.size();

    REP(i, K) ps.emplace_back(ps[i]);
    REP(i, K) ps[i + K].theta += PI * 2;
    lint ret = 0;
    REP(i, K) {
        P p = ps[i];
        p.theta += PI;
        p.x *= -1;
        p.y *= -1;
        auto itr = lower_bound(ps.begin() + i, ps.begin() + i + K, p);
        lint n = itr - ps.begin() - i;
        ret += (n - 1) * (n - 2) * (n - 3) / 6;
    }
    return ret;
}

int main()
{
    lint N;
    cin >> N;
    pdd.resize(N);
    REP(i, N) cin >> pdd[i].first >> pdd[i].second;
    lint ret = 0;
    REP(i, N) ret += (N - 1) * (N - 2) * (N - 3) * (N - 4) / 24 - solve_bad(i);
    cout << ret << endl;
}