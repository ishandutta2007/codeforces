/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int x,y,k;
    cin>>x>>y>>k;

    int a[k+1],b[k+1];
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>b[i];

    int freqb[x+1]={0},freqg[y+1]={0},ans=0;
    for(int i=1;i<=k;i++)
    {
        int tmp=i-1;
        tmp-=freqb[a[i]];
        tmp-=freqg[b[i]];
        freqb[a[i]]++;
        freqg[b[i]]++;
        ans+=tmp;
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