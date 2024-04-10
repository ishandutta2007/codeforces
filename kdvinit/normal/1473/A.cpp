/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,d;
    cin>>n>>d;

    int a[n+1],pos=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>d) pos=0;
    }

    sort(a+1,a+n+1);

    int x=a[1]+a[2];
    if(x<=d || pos==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}