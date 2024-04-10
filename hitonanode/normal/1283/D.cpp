#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
 
vector<lint> x;
 
int N;
lint cou(lint dmax) {
    lint now = -1e10;
    lint ret = 0;
    REP(i, N) {
        mmax(now, x[i] - dmax);
        ret += x[i] - now - 1;
        now = x[i];
        lint add = min(dmax, x[i + 1] - x[i] - 1);
        ret += add;
        now += add;
    }
    return ret;
}
int main()
{
    int M;
    cin >> N >> M;
    x.resize(N);
    cin >> x;
    x.push_back(1e10);
    sort(ALL(x));
    lint l = 0, r = 2e9;
    while (r - l > 1) {
        lint c = (l + r) / 2;
        (cou(c) >= M ? r : l) = c;
    }
    vector<plint> y;
    lint now = -1e10;
    REP(i, N) {
        mmax(now, x[i] - r);
        while (now < x[i + 1] and now <= x[i] + r)
        {
            if (now != x[i]) {
                y.emplace_back(min(abs(now - x[i]), abs(now - x[i + 1])), now);
            }
            now++;
        }
    }
    sort(ALL(y));
    lint ret = 0;
    REP(i, M) ret += y[i].first;
    printf("%lld\n", ret);
    REP(i, M) printf("%lld ", y[i].second);
    puts("");
}