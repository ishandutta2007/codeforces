#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int main()
{
    int N;
    cin >> N;
    vector<lint> A(N), B(N);
    cin >> A >> B;
    map<lint, int> c;
    for (auto v : A) c[v]++;
    vector<int> use(N);
    for (auto p : c) if (p.second > 1)
    {
        REP(i, N) if ((A[i] & ~p.first) == 0) use[i] = 1;
    }
    lint ret = 0;
    REP(i, N) if (use[i]) ret += B[i];
    cout << ret << endl;
}