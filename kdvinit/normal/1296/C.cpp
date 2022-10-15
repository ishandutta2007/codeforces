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

    map< pair<int,int> , int>  lst;
    int x=0, y=0;
    int ans=n+5,l,r;
    for(int i=1;i<=n;i++)
    {
        char z;
        cin>>z;

        if(z=='L') x--;
        if(z=='R') x++;
        if(z=='U') y++;
        if(z=='D') y--;


        int ind=lst[{x,y}];
        //cout<<ind<<endl;
        int len=i-ind+1;
        if(ind!=0 && len<=ans)
        {
            l=ind+1;
            r=i;
            ans=len;
        }

        if(x==0 && y==0  && i<=ans)
        {
            l=ind+1;
            r=i;
            ans=len;
        }

        lst[{x,y}]=i;
    }

    if(ans==n+5) cout<<-1<<endl;
    else cout<<l<<" "<<r<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}