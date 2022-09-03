#include <bits/stdc++.h>

using namespace std;

const int M = 1e5;

int n, a, m = 1e9;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m = min(m, a / max(i, n - 1 - i));
    }
    cout << m;
    return 0;
}