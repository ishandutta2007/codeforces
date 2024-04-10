/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, p;
    cin>>n>>p;

    priority_queue< array<int, 2> > pq;

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]>=p) continue;
        pq.push( {-a[i], i} );
    }

    int cnt = n-1;
    int used[n+1]={0};
    int ans = 0;

    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        int i = x[1];
        if(used[i]==1) continue;

        int w = a[i];

        int l=i;
        int r=i;

        r++;
        while(1)
        {
            if(r>n) break;
            if(a[r]%a[i]!=0) break;
            if(used[r]==1) { r++; break; }
            used[r]=1;
            r++;
        }

        l--;
        while(1)
        {
            if(l<1) break;
            if(a[l]%a[i]!=0) break;
            if(used[l]==1) { l--; break; }
            used[l]=1;
            l--;
        }

        int tmp = r-l-2;
        ans += (a[i]*tmp);
        cnt-=tmp;

        //cout<<i<<" "<<a[i]<<" "<<l<<" "<<r<<endl;
    }

    ans+=(p*cnt);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}