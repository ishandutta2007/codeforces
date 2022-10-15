/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int min_val(int n1, int n2, int n3, int r[], int g[], int b[])
{
    int ans = 5*(1e18);

    int j=1, k=1;
    for(int i=1; i<=n1; i++)
    {
        while(j!=n2+1 && g[j]<r[i]) j++;
        while(k!=n3+1 && b[k]<r[i]) k++;

        int j_nd=0, k_nd=0;
        if(j==n2+1) j_nd=1;
        if(k==n3+1) k_nd=1;

        if(k!=1 && j!=n2+1)
        {
            int x = b[k-1];
            int y = r[i];
            int z = g[j];

            int tmp = (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
            ans = min(ans, tmp);
        }
        if(j!=1 && k!=n3+1)
        {
            int x = g[j-1];
            int y = r[i];
            int z = b[k];

            int tmp = (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
            ans = min(ans, tmp);
        }

        if(j!=n2+1 && k!=n3+1)
        {
            int x = g[j];
            int y = r[i];
            int z = b[k];

            int tmp = (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
            ans = min(ans, tmp);
        }
    }

    return ans;
}

void solve()
{
    int n1, n2, n3;
    cin>>n1>>n2>>n3;

    int r[n1+1], g[n2+1], b[n3+1];

    for(int i=1; i<=n1; i++) cin>>r[i];
    for(int i=1; i<=n2; i++) cin>>g[i];
    for(int i=1; i<=n3; i++) cin>>b[i];

    sort(r+1, r+n1+1);
    sort(g+1, g+n2+1);
    sort(b+1, b+n3+1);

    int ans1 = min_val(n1, n2, n3, r, g, b);
    int ans2 = min_val(n3, n1, n2, b, r, g);
    int ans3 = min_val(n2, n3, n1, g, b, r);

    int ans = min(ans1, ans2);
    ans = min(ans, ans3);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}