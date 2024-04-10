/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    char a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int rgb[n+1]={0},gbr[n+1]={0},brg[n+1]={0};

    char s1[]={'R','G','B'};
    char s2[]={'G','B','R'};
    char s3[]={'B','R','G'};

    for(int i=1;i<=n;i++)
    {
        rgb[i]=rgb[i-1];
        brg[i]=brg[i-1];
        gbr[i]=gbr[i-1];

        int l=(i-1)%3;
        if(s1[l]!=a[i]) rgb[i]++;
        if(s2[l]!=a[i]) gbr[i]++;
        if(s3[l]!=a[i]) brg[i]++;
    }

    int ans=n;
    for(int i=k;i<=n;i++)
    {
        ans=min(ans,rgb[i]-rgb[i-k]);
        ans=min(ans,brg[i]-brg[i-k]);
        ans=min(ans,gbr[i]-gbr[i-k]);
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