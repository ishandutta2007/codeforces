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



int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    int M = N / 4;
    int V = 0;
    REP(i, M)
    {
        REP(j, M * 2)
        {
            A[i * 4 + 0][j * 2 + 1] = V++;
            A[i * 4 + 3][j * 2 + 0] = V++;
            A[i * 4 + 2][j * 2 + 0] = V++;
            A[i * 4 + 1][j * 2 + 1] = V++;
            A[i * 4 + 1][j * 2 + 0] = V++;
            A[i * 4 + 2][j * 2 + 1] = V++;
            A[i * 4 + 3][j * 2 + 1] = V++;
            A[i * 4 + 0][j * 2 + 0] = V++;
        }
    }

    REP(i, N)
    {
        REP(j, N) printf("%d ", A[i][j]);
        puts("");
    }
}