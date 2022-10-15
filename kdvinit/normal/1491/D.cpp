/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int u, v;
    cin>>u>>v;

    if(u>v) { cout<<"NO"<<endl; return; }

    int bu[35]={0};
    int cntu=1;
    int mu=0;
    int x=u;
    while(x!=0)
    {
        bu[cntu]=x%2;
        mu+=bu[cntu];
        x/=2;
        cntu++;
    }

    int bv[35]={0};
    int cntv=1;
    int mv=0;
    x=v;
    while(x!=0)
    {
        bv[cntv]=x%2;
        mv+=bv[cntv];
        x/=2;
        cntv++;
    }

    if(mv>mu) { cout<<"NO"<<endl; return; }

    int i=1, j=1;
    for(i=1;i<=34;i++)
    {
        if(bu[i]==0) continue;
        while(bv[j]==0) j++;
        if(i>j) { cout<<"NO"<<endl; return; }
        j++;
    }

    cout<<"YES"<<endl;



    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}