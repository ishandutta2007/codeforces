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

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans = n*a[1] + n*a[2];
    int mno = a[1];
    int mne = a[2];
    int sum = a[1]+a[2];

    for(int i=3;i<=n;i++)
    {
        if(i%2==1) mno = min(mno, a[i]);
        else mne = min(mne, a[i]);

        sum+=a[i];
        int le = (i/2);
        int lo = i - le;
        int tmp = sum + (n-le)*(mne) + (n-lo)*(mno);
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