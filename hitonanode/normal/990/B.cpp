#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    cin >> A;
    sort(A.begin(), A.end());
    int ret = N;
    REP(i, N) {
        auto itr = upper_bound(A.begin(), A.end(), A[i]);
        if (itr != A.end() and *itr <= A[i] + K) ret--;
    }
    cout << ret << "\n";
}