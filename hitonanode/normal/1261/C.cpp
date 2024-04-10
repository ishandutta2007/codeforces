#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    cin >> S;
    vector<vector<int>> AC(N + 1, vector<int>(M + 1));
    REP(i, N) REP(j, M) if (S[i][j] == 'X') AC[i + 1][j + 1]++;
    REP(i, N + 1) REP(j, M) AC[i][j + 1] += AC[i][j];
    REP(i, N) REP(j, M + 1) AC[i + 1][j] += AC[i][j];

    int l = 0, r = min(N, M) / 2 + 10;
    while (r - l > 1)
    {
        int c = (l + r) / 2;
        int A = 1 + c * 2;
        vector<vector<int>> im(N + 1, vector<int>(M + 1));
        REP(i, N - A + 1) REP(j, M - A + 1)
        {
            int tot = AC[i + A][j + A] - AC[i][j + A] - AC[i + A][j] + AC[i][j];
            if (tot == A * A)
            {
                im[i][j]++, im[i][j + A]--, im[i + A][j]--, im[i + A][j + A]++;
            }
        }
        REP(i, N + 1) REP(j, M) im[i][j + 1] += im[i][j];
        REP(i, N) REP(j, M + 1) im[i + 1][j] += im[i][j];
        bool f = true;
        REP(i, N) REP(j, M) if (!im[i][j] and S[i][j] == 'X') f = false;
        (f ? l : r) = c;
    }
    vector<string> ret = S;
    int A = 1 + l * 2;
    REP(i, N) REP(j, M) ret[i][j] = '.';
    REP(i, N) REP(j, M)
    {
        if (i + A <= N and j + A <= M and AC[i + A][j + A] - AC[i][j + A] - AC[i + A][j] + AC[i][j] == A * A)
        {
            ret[i + l][j + l] = 'X';
        }
    }
    printf("%d\n", l);
    for (auto s : ret) printf("%s\n", s.c_str());
}