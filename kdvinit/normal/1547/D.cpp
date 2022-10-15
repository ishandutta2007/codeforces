/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int x[n+1], y[n+1]={0};
    for(int i=1; i<=n; i++) cin>>x[i];

    int p2=1;
    for(int i=1; i<=31; i++)
    {
        int flag=0;
        for(int j=1; j<=n; j++)
        {
            if(x[j]%2==1) flag=1;
            else y[j]+=(p2*flag);
            x[j]/=2;
        }
        p2*=2;
    }
    for(int i=1; i<=n; i++) cout<<y[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}