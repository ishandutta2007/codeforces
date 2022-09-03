#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

lint N, K_;
lint l1, r1, l2, r2;

lint eval(lint x)
{
    lint K = K_;
    lint intr = max(min(r1, r2) - l2, 0LL);
    K -= intr * x;
    if (K <= 0) return 0;
    lint m = min((max(r1, r2) - l1 - intr) * x, K);
    lint gap = max(l2 - r1, 0LL);
    lint ret = gap * x + m + (K - m) * 2;
    return ret;
}

lint solve()
{
    cin >> N >> K_ >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2) swap(l1, l2), swap(r1, r2);
    lint ret = 1e18;
    for (int x = 1; x <= N; x++) ret = min(ret, eval(x));
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}