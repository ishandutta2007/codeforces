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

    int freq[k+1]={0};
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        freq[x]++;
    }

    int lo=0,ans=0;
    for(int i=1;i<=k;i++)
    {
        int x=freq[i];
        if(x%2==0) ans+=x;
        else
        {
            if(lo==0) { ans+=x; lo=1; }
            else { ans+=(x-1); lo=0; }
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}