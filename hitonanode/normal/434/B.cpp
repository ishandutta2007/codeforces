#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int N, M, Q;

int main()
{
    cin >> N >> M >> Q;
    vector<bitset<1001>> V1(N), V1i(N), V2(M), V2i(M);

    vector<vector<int>> A;
    ndarray(A, N, M);
    cin >> A;

    REP(i, N) V1[i].flip(), V1i[i].flip();
    REP(i, M) V2[i].flip(), V2i[i].flip();

    REP(i, N) REP(j, M) if (A[i][j])
    {
        V1[i].reset(j);
        V1i[i].reset(M - 1 - j);
        V2[j].reset(i);
        V2i[j].reset(N - 1 - i);
    }

    REP(_, Q)
    {
        int op, x, y;
        cin >> op >> x >> y;
        x--;
        y--;
        if (op == 1)
        {
            V1[x].flip(y);
            V1i[x].flip(M - 1 - y);
            V2[y].flip(x);
            V2i[y].flip(N - 1 - x);
        }
        else
        {
            int ret = 0, yimax = M, ymax = M;
            FOR(xx, x, N)
            {
                if (V1[xx][y]) break;
                mmin(ymax, (int)V1[xx]._Find_next(y));
                mmin(yimax, (int)V1i[xx]._Find_next(M - 1 - y));
                mmax(ret, (xx - x + 1) * (-1 + ymax - y + yimax - (M - 1 - y)));
            }
            yimax = M, ymax = M;
            IREP(xx, x + 1)
            {
                if (V1[xx][y]) break;
                mmin(ymax, (int)V1[xx]._Find_next(y));
                mmin(yimax, (int)V1i[xx]._Find_next(M - 1 - y));
                mmax(ret, (x - xx + 1) * (-1 + ymax - y + yimax - (M - 1 - y)));
            }
            int ximax = N, xmax = N;
            FOR(yy, y, M)
            {
                if (V1[x][yy]) break;
                mmin(xmax, (int)V2[yy]._Find_next(x));
                mmin(ximax, (int)V2i[yy]._Find_next(N - 1 - x));
                mmax(ret, (yy - y + 1) * (-1 + xmax - x + ximax - (N - 1 - x)));
            }
            ximax = N, xmax = N;
            IREP(yy, y + 1)
            {
                if (V1[x][yy]) break;
                mmin(xmax, (int)V2[yy]._Find_next(x));
                mmin(ximax, (int)V2i[yy]._Find_next(N - 1 - x));
                mmax(ret, (y - yy + 1) * (-1 + xmax - x + ximax - (N - 1 - x)));
            }
            printf("%d\n", ret);
        }
    }
}