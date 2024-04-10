/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<double> px,nx;
    int pi=0,ni=0;
    double x,y,u,v,z;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>u>>v;
        x=u-x;
        y=v-y;
        if(x==0)
        {
            if(y>0) pi++;
            else ni++;
            continue;
        }

        z=y/x;
        if(x>0) px.push_back(z);
        else nx.push_back(z);
    }

    sort(px.begin(),px.end());
    sort(nx.begin(),nx.end());

    int pxi=0,nxi=0;

    int ans=0;
    while(pxi<px.size() && nxi<nx.size())
    {
        if(px[pxi]>nx[nxi])
        {
            nxi++;
            continue;
        }

        if(px[pxi]<nx[nxi])
        {
            pxi++;
            continue;
        }

        x=px[pxi];

        int cnt1=0,cnt2=0;

        while(pxi<px.size() && px[pxi]==x)
        {
            pxi++;
            cnt1++;
        }

        while(nxi<nx.size() && nx[nxi]==x)
        {
            nxi++;
            cnt2++;
        }

        ans+=(cnt1)*(cnt2);
    }

    ans+=(pi)*(ni);
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    std::cout << std::setprecision(15); std::cout << std::fixed;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}