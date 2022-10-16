/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n,x,y,diff,temp,gap=1,strt;
    cin>>n>>x>>y;

    diff=y-x;
    while(1)
    {
        if(diff%gap==0)
        {
            temp=(diff/gap);
            if(temp+1<=n) break;
        }
        gap++;
    }

    //cout<<gap<<endl;

    strt=( y - ((n-1)*gap) );
    strt=max(strt,y%gap);

    if(strt==0) strt=gap;

    for(int i=0;i<n;i++)
    {
        temp=strt+(i*gap);
        cout<<temp<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}