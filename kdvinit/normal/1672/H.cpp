/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, q;
    cin>>n>>q;

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i] = x-'0';
    }

    int cnt0[n+1]={0}, cnt1[n+1]={0};

    for(int i=1; i<=n; i++)
    {
        cnt0[i] = cnt0[i-1];
        cnt1[i] = cnt1[i-1];

        if(a[i]==0) cnt0[i]++;
        else cnt1[i]++;
    }

    int swp[n+1]={0};
    for(int i=2; i<=n; i++)
    {
        swp[i]=swp[i-1];
        if(a[i]!=a[i-1]) swp[i]++;
    }

    while(q--)
    {
        int l, r;
        cin>>l>>r;

        int len = swp[r]-swp[l]+1;

        int c0 = cnt0[r] - cnt0[l-1];
        int c1 = cnt1[r] - cnt1[l-1];

        int l2 = len/2;
        c0 -= l2;
        c1 -= l2;

        if(len%2==1)
        {
            if(a[l]==0) c0--;
            else c1--;
        }

        int ans = 1 + max(c0, c1);
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}