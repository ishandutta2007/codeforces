#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int X, Y, A, B;
    cin >> X >> Y >> A >> B;
    int D = Y - X, V = A + B;
    if (D % V) return -1;
    return D / V;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}