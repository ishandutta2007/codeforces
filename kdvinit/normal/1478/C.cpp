/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int m=2*n;

    int d[m+1];
    for(int i=1;i<=m;i++) cin>>d[i];
    sort(d+1,d+m+1);

    for(int i=2;i<=m;i+=2)
    {
        if(d[i]!=d[i-1]) { cout<<"NO"<<endl; return; }
    }

    int lst=0;
    int ans[n+1]={0};
    for(int i=m;i>=2;i-=2)
    {
        int x=d[i]-lst;
        if(x%i!=0) { cout<<"NO"<<endl; return; }
        x/=i;
        ans[(i/2)]=x;
        lst+=(2*x);
    }
    
    if(ans[1]<=0) { cout<<"NO"<<endl; return; }
    for(int i=2;i<=n;i++)
    {
        if(ans[i]<=0 || ans[i]==ans[i-1]) { cout<<"NO"<<endl; return; }
    }
    
    cout<<"YES"<<endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}