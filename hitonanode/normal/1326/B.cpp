#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main()
{
    int N;
    cin >> N;
    vector<lint> B(N);
    for (auto &b : B) cin >> b;
    vector<lint> A(N);
    vector<lint> X(N + 1);
    REP(i, N) {
        A[i] = B[i] + X[i];
        X[i + 1] = max(X[i], A[i]);
    }
    for (auto x : A) printf("%lld ", x);
    puts("");
}