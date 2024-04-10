#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N, M;
    cin >> N >> M;
    if (N > M) {
        puts("0");
        return 0;
    }
    vector<int> A(N);
    cin >> A;
    long long int ret = 1;
    REP(i, N) REP(j, i) ret = ret * abs(A[i] - A[j]) % M;
    cout << ret << endl;
}