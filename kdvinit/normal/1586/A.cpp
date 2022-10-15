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

    int oddi, sum=0;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        sum+=x;
        if(x%2==1) oddi=i;
    }

    int p=1;
    for(int i=2; i*i<=sum; i++)
    {
        if(sum%i==0) p=0;
    }

    if(p==1)
    {
        cout<<n-1<<endl;
        for(int i=1; i<=n; i++)
        {
            if(i!=oddi) cout<<i<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<n<<endl;
        for(int i=1; i<=n; i++) cout<<i<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}