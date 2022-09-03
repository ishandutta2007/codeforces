#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve()
{
    int N;
    cin >> N;
    vector<int> odd, even;
    FOR(i, 1, N * 2 + 1)
    {
        int a;
        cin >> a;
        (a % 2 ? odd : even).emplace_back(i);
    }
    REP(_, N - 1)
    {
        if (odd.size() > 1)
        {
            cout << odd.back() << ' ';
            odd.pop_back();
            cout << odd.back() << '\n';
            odd.pop_back();
        }
        else
        {
            cout << even.back() << ' ';
            even.pop_back();
            cout << even.back() << '\n';
            even.pop_back();
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}