#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int S;
    cin >> S;
    int ret = 0;
    while (S >= 10) {
        int u = S / 10 * 10;
        ret += u, S -= u - u / 10;
    }
    return ret + S;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}