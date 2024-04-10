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
    if (N % 2 and A[N / 2] != B[N / 2]) return false;
    vector<pair<int, int>> ap, bp;
    REP(i, N / 2)
    {
        int l = i, r = N - 1 - l;
        ap.emplace_back(minmax(A[l], A[r]));
        bp.emplace_back(minmax(B[l], B[r]));
    }
    sort(ap.begin(), ap.end());
    sort(bp.begin(), bp.end());
    return ap == bp;
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