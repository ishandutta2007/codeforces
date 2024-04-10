#include <bits/stdc++.h>
using namespace std;

int solve()
{
    string S;
    cin >> S;
    int lo = 0, hi = S.length() + 1;
    while (hi - lo > 1) {
        int c = (lo + hi) / 2;
        int R = -1 + c;
        for (int i = 0; i < S.length(); i++) if (S[i] == 'R' and i <= R) R = max(R, i + c);
        (R >= S.length() ? hi : lo) = c;
    }
    return hi;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << "\n";
}