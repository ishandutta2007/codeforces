#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;




int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    cin >> A >> B;
    vector<int> cnt(N);
    vector<int> ap(N + 1), bp(N + 1);
    REP(i, N) ap[A[i]] = i, bp[B[i]] = i;
    FOR(i, 1, N + 1) cnt[(ap[i] + N - bp[i]) % N]++;
    cout << *max_element(cnt.begin(), cnt.end()) << '\n';
}