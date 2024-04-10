#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
long n,i,a[5002],in[5002][2]={0},r,f,s,j,sum=0,ans=0,dp[5002]={0},l;
bool cmp(pair < long , long > a , pair < long , long > b )
{
    return a.first<b.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector < pair < long , long > > g;
    map < pair < long , long > , long > v;
    set < long > st;
    cin>>n;
    for(i=1;i<=n;++i)
    cin>>a[i];
    for(i=1;i<=n;++i)
    {
        if(in[a[i]][0]==0) in[a[i]][0]=i;
        in[a[i]][1]=i;
    }
    for(i=1;i<=n;++i)
    {
        r=in[a[i]][1];
        f=1;
        s=0;
        st.clear();
        for(j=i;j<=r;++j)
        {
            if(in[a[j]][0]<i) {f=0;break;}
            if(in[a[j]][1]>r) r=in[a[j]][1];
            if(st.find(a[j])==st.end())
            {
                s=(s^a[j]);
                st.insert(a[j]);
            }
        }
        if(f)
        {
            g.pb({i,r});
            v[{i,r}]=s;
        }
    }
    sort(g.begin(),g.end(),cmp);
    pair <long ,long > p;
    for(i=n;i>0;--i)
    {
        p={i,1e9};
        l=upper_bound(g.begin(),g.end(),p)-g.begin();
        if(g[l-1].first!=i) dp[i]=dp[i+1];
        else dp[i]=max(dp[i+1],v[g[l-1]]+dp[g[l-1].second+1]);
    }
    cout<<dp[1];
    return 0;
}