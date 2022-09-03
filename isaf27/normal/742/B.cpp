#include <bits/stdc++.h>

using namespace std;

const int M = (1 << 18) + 1;

int kol[M];

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> v(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        ans += kol[(v[i] ^ x)];
        kol[(v[i])]++;
    }
    cout << ans;
    return 0;
}