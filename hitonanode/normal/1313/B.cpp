#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

void solve()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    if (Y < X) swap(X, Y);
    int hi = min(X + Y - 1, N);
    int A = X - 1, B = N - Y, D = N - X;
    int lo;
    if (A < B) lo = 1;
    else if (!D) lo = N;
    else if (!B) lo = N - (D - 1);
    else lo = N - D - B + 1;
    cout << lo << " " << hi << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}