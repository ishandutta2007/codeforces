/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int l=0;
    for(int i=1; i<=m; i++)
    {
        int x; cin>>x;
        l=GCD(l, x);
    }

    int cnt[l]={0};
    int num[l];
    for(int i=0; i<l; i++) num[i]=1e10;

    for(int i=1; i<=n; i++)
    {
        int x = abs(a[i]);
        int j = i%l;

        if(a[i]<0) cnt[j]++;
        num[j] = min(num[j], x);
    }

    int sum=0;
    for(int i=1; i<=n; i++) sum+=abs(a[i]);

    int sum1=0, sum2=0;
    for(int i=0; i<l; i++)
    {
        int x = num[i];
        if(cnt[i]%2==0) sum1+=x;
        else sum2+=x;
    }

    int sub = min(sum1, sum2);
    int ans = (sum-(2*sub));
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}