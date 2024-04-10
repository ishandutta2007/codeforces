#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
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

vector<vector<int>> A;
int CD[41][1000][1000];
struct GridGraph
{

    int H, W;
    std::array<int, 4> dx = {1, -1, 0, 0};
    std::array<int, 4> dy = {0, 0, 1, -1};

    GridGraph() = default;
    GridGraph(int h, int w) : H(h), W(w) {}

    int bfs01(std::vector<pint> init, int tgt) {
        queue<pint> q;
        for (auto i : init) q.push(i), CD[tgt][i.first][i.second] = 0;
        while (!q.empty()) {
            pint p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            REP(d, 4) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 or ny < 0 or nx >= H or ny >= W) continue;
                if (mmin(CD[tgt][nx][ny], CD[tgt][x][y] + 1)) q.emplace(nx, ny);
            }
        }
        return 0;
    }
};

int N, M, K;

int main()
{
    cin >> N >> M >> K;
    REP(k, K) REP(i, N) REP(j, M) CD[k][i][j] = 1e9;
    A.resize(N, vector<int>(M));
    cin >> A;
    REP(i, N) REP(j, M) A[i][j]--;
    GridGraph g(N, M);
    REP(k, K) {
        vector<pint> v;
        REP(i, N) REP(j, M) if (A[i][j] == k) v.emplace_back(i, j);
        g.bfs01(v, k);
    }
    vector<vector<int>> k2k(K, vector<int>(K, 1e9));
    REP(i, N) REP(j, M) {
        REP(k, K) mmin(k2k[A[i][j]][k], CD[k][i][j]);
        REP(k, K) mmin(k2k[k][A[i][j]], CD[k][i][j]);
    }

    REP(_, 3) REP(k, K) REP(i, K) REP(j, K) mmin(k2k[i][j], k2k[i][k] + k2k[k][j] + 1);

    int Q;
    cin >> Q;
    while (Q--) {
        int r, c, r2, c2;
        cin >> r >> c >> r2 >> c2;
        r--, c--, r2--, c2--;
        int tmp = abs(r - r2) + abs(c - c2);
        if (A[r][c] == A[r2][c2]) mmin(tmp, 1);
        REP(a, K) REP(b, K) mmin(tmp, CD[a][r][c] + k2k[a][b] + (a == b ? 1 : 2) + CD[b][r2][c2]);
        printf("%d\n", tmp);
    }
}