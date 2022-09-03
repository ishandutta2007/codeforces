#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

string solve()
{
    int n;
    cin >> n;
    if (n == 1) return "-1";
    string ret(n, '9');
    ret.back() = '8';
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << "\n";
}