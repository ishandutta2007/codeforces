#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

lint solve(__int128 X)
{
    lint ret = 0;
    __int128 now = 1;
    while (true)
    {
        X -= now * (now + 1) / 2;
        if (X >= 0)
        {
            ret++;
            now = now * 2 + 1;
        }
        else break;
    }
    return ret;
}
lint solve()
{
    lint X;
    cin >> X;
    return solve(X);
}
int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}