/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[105];
int ans[105];
int cnt;

void dfs(int strt,int nd)
{
    int mxv=0,mxi=0;
    if(strt>nd) return;

    if(strt==nd)
    {
        ans[strt]=cnt;
        return;
    }

    for(int i=strt;i<=nd;i++)
    {
        if(a[i]>=mxv)
        {
            mxv=a[i];
            mxi=i;
        }
    }

    ans[mxi]=cnt;

    cnt++;
    dfs(strt,mxi-1);
    dfs(mxi+1,nd);
    cnt--;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];

    cnt=0;
    dfs(1,n);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}