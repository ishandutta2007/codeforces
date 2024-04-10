#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    int ret = N * 2 - 1;
    REP(i, N - 2) {
        bool good = true;
        if (A[i] <= A[i + 1] and A[i + 1] <= A[i + 2]) good = false;
        if (A[i] >= A[i + 1] and A[i + 1] >= A[i + 2]) good = false;
        ret += good;
        if (good and i + 3 < N) {
            REP(t, 2) {
                REP(d, 4) A[i + d] *= -1;
                if (A[i] <= A[i + 1] and A[i + 1] <= A[i + 3]) good = false;
                if (A[i] <= A[i + 2] and A[i + 2] <= A[i + 3]) good = false;
                if (A[i + 1] <= A[i + 2] and A[i + 2] <= A[i + 3]) good = false;
            }
            ret += good;
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}