/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;
    n--;

    int tim=0, cur=1;
    while(cur<=k && n>0)
    {
        tim++;
        n-=cur;
        cur*=2;
    }

    if(n>0)
    {
        int tmp = (n-1)/k;
        tim+=(tmp+1);
    }

    cout<<tim<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}