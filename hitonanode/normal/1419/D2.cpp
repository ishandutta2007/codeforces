#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    sort(A.rbegin(), A.rend());
    int lo = 0, hi = (N + 1) / 2;
    while (hi - lo > 1)
    {
        int c = (lo + hi) / 2;
        bool flg = true;
        REP(i, c)
        {
            if (A[i] <= A[N - c + i] or A[i + 1] <= A[N - c + i]) flg = false;
        }
        (flg ? lo : hi) = c;
    }
    cout << lo << '\n';
    vector<int> ret{A[0]}, used(N);
    used[0] = 1;
    REP(i, lo)
    {
        ret.emplace_back(A[N - lo + i]);
        used[N - lo + i] = true;
        ret.emplace_back(A[i + 1]);
        used[i + 1] = true;
    }
    REP(i, N) if (!used[i]) ret.emplace_back(A[i]);
    for (auto x : ret) cout << x << ' ';
    cout << '\n';
}