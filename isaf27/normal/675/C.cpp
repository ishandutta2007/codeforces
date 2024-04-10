#include <bits/stdc++.h>

using namespace std;

long long n, a, s;
map<long long, int> m;

int main()
{
    cin >> n;
    s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s += a;
        m[s]++;
    }
    int kol = 0;
    for (auto t : m)
        kol = max(kol, t.second);
    cout << n - kol;
    return 0;
}