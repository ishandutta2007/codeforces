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

    int x[n+1], y[n+1];
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];

    sort(x+1,x+n+1);
    sort(y+1,y+n+1);

    int m=((n+1)/2);
    if(n%2==1) cout<<1<<endl;
    else
    {
        int xx=x[m+1]-x[m]+1;
        int yy=y[m+1]-y[m]+1;
        cout<<xx*yy<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}