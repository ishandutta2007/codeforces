#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

bool solve()
{
    int A, B;
    cin >> A >> B;
    return __gcd(A, B) != 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "Infinite" : "Finite") << endl;
}