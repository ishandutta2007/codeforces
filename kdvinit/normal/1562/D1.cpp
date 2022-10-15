/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
//#define endl "\n"

void solve()
{
    int n, q;
    cin>>n>>q;

    int sum[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        int y;

        if(x=='+') y=1;
        else y=-1;

        if(i%2==0) y*=(-1);
        sum[i] = sum[i-1]+y;
    }

    while(q--)
    {
        int l, r;
        cin>>l>>r;
        int ans = abs(sum[r] - sum[l-1]);
        if(ans==0) cout<<0<<endl;
        else
        {
            if(ans%2==1) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}