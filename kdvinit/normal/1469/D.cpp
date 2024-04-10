/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int m=n;
    int ans[n+6][2],cnt=0;
    while(m!=2)
    {
        int i;
        for(i=m-1;(i-1)*(i-1)>=m;i--)
        {
            ans[++cnt][0]=i;
            ans[cnt][1]=m;
        }
        ans[++cnt][0]=m;
        ans[cnt][1]=i;
        ans[++cnt][0]=m;
        ans[cnt][1]=i;
        m=i;
    }

    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}