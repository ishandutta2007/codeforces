#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

bool solve()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    vector<int> cnt(N);
    REP(i, N) cnt[(i + A[i] % N + N) % N]++;
    return *max_element(cnt.begin(), cnt.end()) == 1;
}

int main()
{
    int TC;
    cin >> TC;
    while (TC--) cout << (solve() ? "YES\n" : "NO\n");
}