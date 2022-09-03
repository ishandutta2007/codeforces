#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    int N, A, R, M;
    cin >> N >> A >> R >> M;
    chmin(M, A + R);
    vector<lint> H(N);
    cin >> H;
    vector<pair<lint, int>> cs;
    for (auto h : H) cs.emplace_back(h, 1);
    lint htot = accumulate(ALL(H), 0LL);
    cs.emplace_back(htot / N, 0);
    cs.emplace_back(htot / N + 1, 0);
    sort(ALL(cs));
    lint hless = 0, iless = 0;
    lint ret = 1e18;
    for (auto p : cs)
    {
        lint c = p.first;
        if (c >= 0)
        {
            lint req = iless * c - hless;
            lint yobun = htot - hless - c * (N - iless);
            lint nmv = min(req, yobun);
            lint tmp = nmv * M + (req - nmv) * A + (yobun - nmv) * R;
            chmin(ret, tmp);
        }
        if (p.second)
        {
            hless += c;
            iless++;
        }
    }
    cout << ret << '\n';
}