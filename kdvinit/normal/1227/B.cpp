#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin>>n;
    
    int q[n+1];
    for(int i=1;i<=n;i++) cin>>q[i];
    
    int p[n+1],used[n+1]={0},cnt=1;
    p[1]=q[1]; used[q[1]]=1;
    for(int i=2;i<=n;i++)
    {
        if(q[i]!=q[i-1]) { p[i]=q[i]; used[q[i]]=1; }
        else
        {
            while(used[cnt]==1 && cnt<=n) cnt++;
            used[cnt]=1;
            p[i]=cnt;
        }
    }
    
    int mx=p[1];
    for(int i=2;i<=n;i++)
    {
        mx=max(mx,p[i]);
        if(q[i]!=mx) { cout<<-1<<endl; return; }
    }
    
    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
}


int32_t main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}