/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 100;
int a[N];
int n;

int val(int p, int q, int ind)
{
    int b[n+1];
    for(int i=1; i<=n; i++) b[i]=(a[i]*q);

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int exp = b[ind] + (i-ind)*p;
        if(b[i]!=exp) ans++;
    }

    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    if(n<3) { cout<<0<<endl; return; }

    int ans = n-2;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int tmp = val(a[j]-a[i], j-i, i);
            ans = min(ans, tmp);
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}