#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int BIG = 1e9 + 1;
const int XX = 1e4 + 1;
const ld pi = acos(-1.0);
const int M = 2 * 1e5 + 1;

int n, t[M];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    //cin.sync_with_stdio(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++)
        if (t[i] > 0)
            c[t[i] - 1]++;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (c[i] == 0);
    cout << ans;
    return 0;
}