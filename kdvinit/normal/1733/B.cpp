/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, x, y;
    cin>>n>>x>>y;

    if(min(x, y)!=0) { cout<<-1<<endl; return; }
    x = max(x, y);
    if(x==0) { cout<<-1<<endl; return; }

    int k = n-1;
    if(k%x!=0) { cout<<-1<<endl; return; }

    int cur=1;
    int gms=0;

    for(int i=2; i<=n; i++)
    {
        if(gms==x)
        {
            gms=0;
            cur=i;
        }
        cout<<cur<<" ";
        gms++;
    }

    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}