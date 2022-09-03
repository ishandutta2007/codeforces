#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


bool sol(int l, int r, int x, int x1, int x2) {
    if (x1 == x2 and l + r) return false;
    if (x - l + r < x1) return false;
    if (x - l + r > x2) return false;
    return true;
}

bool solve()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int X, Y, X1, Y1, X2, Y2;
    cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2;
    return sol(A, B, X, X1, X2) && sol(C, D, Y, Y1, Y2);
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << (solve() ? "Yes\n" : "No\n");
}