/*a
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int i=1;
    int ans=0;
    int cnt[n+2]={0};

    for(int i=1;i<=n;i++)
    {
        for(int j=i+2; j<=n && j<=i+a[i]; j++) cnt[j]++;
    }

    while(1)
    {
        if(i>n) break;
        if(i==n)
        {
            a[i]=max(a[i]-cnt[i], (int)1);
            ans+=(a[i]-1);
            break;
        }

        int m=a[i]-cnt[i];
        int tmp=max(m-1, (int)0);
        ans+=tmp;

        int xtra = cnt[i] - a[i] + 1;
        if(xtra>0) cnt[i+1]+=xtra;
        i++;
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