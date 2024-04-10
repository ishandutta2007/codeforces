/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;
int freq[N]={0};
int cost[N]={0};

void solve()
{
    int n,k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    int ans=1e10;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        int cnt=0;
        while(x!=0)
        {
            freq[x]++;
            cost[x]+=cnt;
            if(freq[x]==k) ans=min(ans,cost[x]);

            cnt++;
            x/=2;
        }
        freq[x]++;
        cost[x]+=cnt;
        if(freq[x]==k) ans=min(ans,cost[x]);
    }

    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}