#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 20500;
int a[nmax];
int b[nmax];
bool c[110][nmax];

void solve()
{
    memset(c, 0, sizeof(c));

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    int s = 0;
    for (int i=1; i<=n; i++)
        s+=a[i]+b[i];
    c[0][0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=0; j<=s; j++)
            if (c[i-1][j])
    {
        if (j+a[i] <= s)
            c[i][j+a[i]] = 1;
        if (j+b[i] <= s)
            c[i][j+b[i]] = 1;
    }
    int sum = 0;
    for (int i=0; i<=s; i++)
        if (c[n][i])
            if (2*i <= s)
                sum = max(sum, i);
    int ans = sum*sum + (s-sum)*(s-sum);
    ans *= 1;
    for (int i=1; i<=n; i++)
        ans += (n-2) * a[i] * a[i] + (n-2) * b[i] * b[i];
    cout<<ans<<"\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
        solve();
}