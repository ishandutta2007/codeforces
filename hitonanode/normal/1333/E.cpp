#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

int main()
{
    int N;
    cin >> N;
    if (N <= 2) {
        puts("-1");
        return 0;
    }
    vector<vector<int>> ret(N, vector<int>(N));
    ret[0][0] = N * N - 4;
    ret[0][1] = N * N - 3;
    ret[0][2] = N * N - 1;
    ret[1][0] = N * N - 0;
    ret[1][1] = N * N - 8;
    ret[1][2] = N * N - 2;
    ret[2][0] = N * N - 5;
    ret[2][1] = N * N - 7;
    ret[2][2] = N * N - 6;
    int now = N * N - 9;
    FOR(deg, 3, N) {
        if (deg % 2) {
            REP(i, deg) ret[deg][i] = now--;
            ret[deg][deg] = now--;
            IREP(i, deg) ret[i][deg] = now--;
        }
        else {
            REP(i, deg) ret[i][deg] = now--;
            ret[deg][deg] = now--;
            IREP(i, deg) ret[deg][i] = now--;

        }
        if (deg == 3) swap(ret[3][0], ret[3][1]);
    }

    for (auto v : ret) {
        for (auto x : v) printf("%d ", x);
        puts("");
    }
}