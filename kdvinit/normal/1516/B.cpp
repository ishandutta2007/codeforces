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

    int ans=0;

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        ans^=a[i];
    }

    if(ans==0) { cout<<"YES"<<endl; return; }

    int cur=0;
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        cur^=a[i];
        if(cur==ans)
        {
            cnt++;
            cur=0;
        }
    }

    if(cur==0 && cnt>1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}