#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

using lint = long long;

lint solve() {
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    if (A[0] == A[1]) {
        REP(i, N) if (A[i] != A[0]) return i + 1;
    } else {
        if (A[0] == A[2]) return 2;
        else return 1;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}