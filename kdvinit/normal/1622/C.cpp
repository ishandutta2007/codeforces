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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    int pre[n+1]={0};
    for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];

    if(pre[n]<=k) { cout<<0<<endl; return; }

    int ans = pre[n]-k;

    int cnt=0;
    for(int i=n; i>1; i--)
    {
        cnt++;
        int sum = k-(pre[i-1]-pre[1]);
        int x = sum/(cnt+1);
        if(sum%(cnt+1)!=0 && sum<0) x--;
        int tmp = cnt;
        if(x<a[1]) tmp+=(a[1]-x);
        ans = min(ans, tmp);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}