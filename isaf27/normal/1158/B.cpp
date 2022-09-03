#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, a;
    cin >> n >> k;
    a = (n - k) / 2;
    for (int i = 0; i < n; i++)
        cout << ((i + 1) % (a + 1) == 0);
    return 0;
}