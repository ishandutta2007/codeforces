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
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i] = x-'a'+1;
    }

    int cnt[k+1][27], tot[k+1]={0}, mx[k+1]={0};
    memset(cnt, 0, sizeof(cnt));

    for(int i=1; i<=n; i+=k)
    {
        for(int j=1; j<=k; j++)
        {
            int l = min(j, k+1-j);
            cnt[l][a[i+j-1]]++;
            tot[l]++;
            mx[l] = max(mx[l], cnt[l][a[i+j-1]]);
        }
    }

    int ans=0;
    for(int j=1; j<=k; j++) ans += (tot[j]-mx[j]);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}