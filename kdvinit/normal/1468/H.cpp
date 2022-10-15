#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n,k,m,hk;
    cin>>n>>k>>m;
    hk=k/2;

    int b[m+1]={0},x,y,pos=0;
    for(int i=1;i<=m;i++) cin>>b[i];

    if( (n-m)%(k-1)!=0 ) { cout<<"NO"<<endl; return; }

    for(int i=1;i<=m;i++)
    {
        x=b[i]-i;
        y=(n-b[i])-(m-i);
        if(x>=hk && y>=hk) { cout<<"YES"<<endl; return; }
    }

    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}