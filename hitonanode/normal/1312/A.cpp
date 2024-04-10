#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


string solve()
{
    int N, M;
    cin >> N >> M;
    if (N % M) return "NO";
    else return "YES";
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << "\n";
}