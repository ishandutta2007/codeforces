#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

template <typename T>
vector<vector<T>> trans(vector<vector<T>> v) {
    int H = v.size();
    int W = v[0].size();
    vector<vector<T>> ret(W, vector<T>(H));
    REP(i, H) REP(j, W) ret[j][i] = v[i][j];
    return ret;
}

vector<vector<int>> solve(vector<vector<char>> v, int K) {
    int H = v.size();
    int W = v[0].size();
    vector<vector<int>> ret(H, vector<int>(W + 1));
    REP(i, H) {
        int suc = 0;
        REP(j, W) {
            if (v[i][j] == '#') suc = 0;
            else suc++;

            if (suc >= K)
            {
                ret[i][j - K + 1]++;
                ret[i][j + 1]--;
            }
        }
        REP(j, W) ret[i][j + 1] += ret[i][j];
        ret[i].pop_back();
    }
    return ret;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<char>> S(N, vector<char>(N));
    cin >> S;

    vector<vector<int>> a1 = solve(S, K);
    vector<vector<int>> a2 = trans(solve(trans(S), K));
    int h = 0, w = 0;
    REP(i, N) REP(j, N) if (a1[i][j] + a2[i][j] > a1[h][w] + a2[h][w]) h = i, w = j;
    cout << h + 1 << " " << w + 1 << "\n";
}