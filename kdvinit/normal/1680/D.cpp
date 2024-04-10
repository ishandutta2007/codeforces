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

    int pres[n+1]={0}, pre0[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        pres[i]=pres[i-1]+a[i];
        pre0[i]=pre0[i-1];
        if(a[i]==0) pre0[i]++;
    }

    int ts=pres[n];
    int t0=pre0[n];

    if(abs(ts) > (t0*k)) { cout<<-1<<endl; return; }

    int ans=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            int cs=pres[j]-pres[i-1];
            int c0=pre0[j]-pre0[i-1];
            int rs=ts-cs;
            int r0=t0-c0;

            int l1 = -rs - (k*r0);
            int r1 = -rs + (k*r0);

            int l2 = cs - (k*c0);
            int r2 = cs + (k*c0);

            int mxp = min(r1, r2);
            int mnp = max(l1, l2);

            int tmp = max(abs(mxp), abs(mnp)) + 1;
            ans = max(ans, tmp);

            //cout<<i<<" "<<j<<" -> "<<mxp<<" "<<mnp<<endl;
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}