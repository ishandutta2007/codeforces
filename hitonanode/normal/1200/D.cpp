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

int main()
{
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    REP(i, N) cin >> S[i];

    vector<vector<int>> imos;
    ndarray(imos, N + 1, N + 1);
    REP(_, 2)
    {
        REP(i, N)
        {
            int leftmost = N, rightmost = -1;
            REP(j, N) if (S[i][j] == 'B') mmin(leftmost, j), mmax(rightmost, j);
            if (leftmost + K - 1 >= rightmost)
            {
                if (leftmost == N)
                {
                    imos[0][0]++;
                    continue;
                }
                int a = max(i - K + 1, 0);
                int b = max(rightmost - K + 1, 0);
                int c = min(leftmost + 1, N);
                imos[a][b]++;
                imos[a][c]--;
                imos[i + 1][b]--;
                imos[i + 1][c]++;
            }
        }

        REP(i, N) REP(j, i) swap(S[i][j], S[j][i]);
        REP(i, N + 1) REP(j, i) swap(imos[i][j], imos[j][i]);
    }

    REP(i, N + 1) REP(j, N) imos[i][j + 1] += imos[i][j];
    REP(j, N + 1) REP(i, N) imos[i + 1][j] += imos[i][j];

    int ret = 0;
    REP(i, N - K + 1) REP(j, N - K + 1) mmax(ret, imos[i][j]);
    cout << ret << endl;
}