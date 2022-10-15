/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int q,d;
    cin>>q>>d;

    int mx=10*d;
    int pos[100]={0};
    pos[0]=1;

    for(int i=0;i<d;i++)
    {
        int val=(10*i)+d;
        for(int j=0;j<=mx;j++)
        {
            if(pos[j]==0) continue;
            for(int k=j;k<=mx;k+=val) pos[k]=1;
        }
    }

    for(int i=1;i<=q;i++)
    {
        int x; cin>>x;
        if(x>=mx) { cout<<"YES"<<endl; continue; }

        if(pos[x]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}