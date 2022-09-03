#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

bool solve()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    cin >> A >> B;
    int n = accumulate(B.begin(), B.end(), 0);
    if (n == 0 or n == N)
    {
        REP(i, N - 1) if (A[i] > A[i + 1]) return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cout << (solve() ? "Yes" : "No") << '\n';
    }
}