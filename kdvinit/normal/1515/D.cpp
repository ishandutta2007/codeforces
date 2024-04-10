/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, l, r;
    cin>>n>>l>>r;

    int cntl[n+1]={0}, cntr[n+1]={0};

    for(int i=1; i<=l; i++)
    {
        int x; cin>>x;
        cntl[x]++;
    }

    for(int i=1; i<=r; i++)
    {
        int x; cin>>x;
        cntr[x]++;
    }

    int ans=0;
    int L=0, R=0;
    for(int i=1; i<=n; i++)
    {
        if(cntl[i]<cntr[i])
        {
            cntr[i] = cntr[i]-cntl[i];
            cntl[i]=0;

            ans += (cntr[i]/2);
            R += (cntr[i]/2);
            cntr[i] = cntr[i]%2;
        }
        else
        {
            cntl[i] = cntl[i]-cntr[i];
            cntr[i]=0;

            ans += (cntl[i]/2);
            L += (cntl[i]/2);
            cntl[i] = cntl[i]%2;
        }
    }

    int l2=0, r2=0;
    for(int i=1; i<=n; i++)
    {
        l2+=cntl[i];
        r2+=cntr[i];
    }

    if(l2<r2)
    {
        ans+=r2;
        int diff = r2-l2;

        int y = min(diff, 2*L);
        y/=2;

        ans-=y;
    }
    else
    {
        ans+=l2;
        int diff = l2-r2;

        int y = min(diff, 2*R);
        y/=2;

        ans-=y;
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