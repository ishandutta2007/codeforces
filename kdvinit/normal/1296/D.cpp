/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,a,b,k;
    cin>>n>>a>>b>>k;

    vector<int> xtra;
    int x,ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        x%=(a+b);
        if(x>0 && x<=a) ans++;
        else
        {
            if(x==0) x=a+b;
            x-=a;
            xtra.push_back(x);
        }
    }

    sort(xtra.begin(),xtra.end());

    for(int i=0;i<xtra.size();i++)
    {
        x=xtra[i];
        int y = ((x-1)/a) + 1;
        k-=y;
        if(k<0) break;
        ans++;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}