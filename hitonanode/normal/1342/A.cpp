#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        lint X, Y, A, B;
        cin >> X >> Y >> A >> B;
        lint ret = abs<lint>(X - Y) * A + min<lint>(X, Y) * min(A * 2, B);
        cout << ret << '\n';
    }
}