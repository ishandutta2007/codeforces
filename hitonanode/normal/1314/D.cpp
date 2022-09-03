#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<lint>> D(N, vector<lint>(N));
    cin >> D;
    vector<vector<vector<pint>>> ij2s;
    ndarray(ij2s, N, N, 0);
    REP(i, N) REP(j, N) {
        REP(k, N) if (i != k and j != k) ij2s[i][j].emplace_back(D[i][k] + D[k][j], k);
        sort(ALL(ij2s[i][j]));
    }

    lint ret = 1e18;
    int NS = 1;
    REP(_, K / 2 - 1) NS *= N;
    vector<int> v(K / 2 + 1);
    REP(S, NS) {
        int T = S;
        REP(i, K / 2 - 1) {
            v[i + 1] = T % N;
            T /= N;
        }
        lint cost_tmp = 0;
        REP(d, v.size() - 1) {
            bool fin = false;
            for (auto p : ij2s[v[d]][v[d + 1]]) {
                bool flg = true;
                for (auto x : v) if (p.second == x) flg = false;
                if (flg) {
                    cost_tmp += p.first;
                    fin = true;
                    break;
                }
            }
            if (!fin) cost_tmp += 1e16;
        }
        chmin(ret, cost_tmp);
    }
    cout << ret << "\n";
}