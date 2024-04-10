#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) {
        cin >> x;
    }
    lint ret = 0;
    REP(_, 2) {
        REP(i, N)
        {
            lint acc = 0;
            FOR(j, i + 1, N - 1) {
                acc += A[j];
                if (acc > A[i] * 2) {
                    break;
                }
                if ((A[i] ^ A[j + 1]) == acc) {
                    ret += (A[i] > A[j + 1]) + (A[i] >= A[j + 1]);
                }
            }
        }
        reverse(A.begin(), A.end());
    }
    cout << ret / 2 << '\n';
}