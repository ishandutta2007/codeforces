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
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    int s[m+1];
    for(int i=1;i<=m;i++) cin>>s[i];
    sort(s+1,s+m+1);

    int k=abs(b-a)-1,l;
    if(b>a) l=a;
    else l=n-a+1;

    int cnt=k+l,ans=0;
    k=min(k,m);

    for(int i=k;i>0;i--)
    {
        if(s[i]>=cnt) continue;
        ans++;
        cnt--;
    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}