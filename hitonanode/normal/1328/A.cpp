#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

void solve()
{
    int A, B;
    cin >> A >> B;
    cout << (B - A % B) % B << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}