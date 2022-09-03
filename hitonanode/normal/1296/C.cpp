#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string S;
    cin >> S >> S;
    map<long long int, int> prv;
    prv[0] = -1;

    int L = -1, R = 1e9;
    int i = 0;
    long long int acc = 0;
    for (auto c : S)
    {
        if (c == 'U') acc += 1;
        if (c == 'D') acc -= 1;
        if (c == 'L') acc += 1LL << 30;
        if (c == 'R') acc -= 1LL << 30;

        if (prv.count(acc) and i - prv[acc] < R - L) L = prv[acc], R = i;
        prv[acc] = i++;
    }
    if (R < 1e9) printf("%d %d\n", L + 2, R + 1);
    else puts("-1");
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}