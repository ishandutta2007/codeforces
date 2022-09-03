#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    int N, K, L;
    cin >> N >> K >> L;
    int M = N * K;
    vector<lint> A(M);
    cin >> A;
    sort(A.begin(), A.end());
    lint hi = A[0] + L;
    auto itr = upper_bound(A.begin(), A.end(), hi);
    int nb = itr - A.begin();
    if (nb < N) {
        puts("0");
        return 0;
    }
    int rem = nb - N;
    lint ret = 0;
    int i = 0;
    REP(_, N) {
        ret += A[i];
        i++;
        int d = max(min(K - 1, rem), 0);
        rem -= d;
        i += d;
    }
    cout << ret << "\n";
}