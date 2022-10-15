/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int tot=0;

    int a[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='R') a[i]=1;

        if(a[i]==0) tot+=(i-1);
        else tot+=(n-i);
    }

    int val[n+1]={0};
    int cnt=0;

    val[0]=tot;
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
        {
            int j = (i+1)/2;
            if(a[j]==1) continue;

            int del = (n-j)-(j-1);
            val[cnt+1]=val[cnt]+del;
            cnt++;
        }
        else
        {
            int j = n+1-(i/2);
            if(a[j]==0) continue;

            int del = (j-1)-(n-j);
            val[cnt+1]=val[cnt]+del;
            cnt++;
        }
    }

    for(int i=cnt+1; i<=n; i++) val[i]=val[cnt];

    for(int i=1; i<=n; i++) cout<<val[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}