#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int N, M;
vector<string> solve(vector<string> A)
{
    vector<string> ret(N + 1, string(M, '0'));
    REP(i, N) {
        ret[i + 1] = ret[i];
        REP(j, M) if (A[i][j] == '1') ret[i + 1][j] = '1';
    }
    return ret;
}

int main()
{
    cin >> N >> M;
    vector<string> A(N);
    cin >> A;
    vector<string> a1 = solve(A);
    reverse(A.begin(), A.end());
    vector<string> a2 = solve(A);
    reverse(a2.begin(), a2.end());

    REP(i, N) {
        bool f = true;
        REP(j, M) if (a1[i][j] == '0' and a2[i + 1][j] == '0') f = false;
        if (f) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}