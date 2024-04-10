#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long n,f,k[100005],l[100005],i,ans=0,in,fa;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector < pair  <long long ,long long > > v;
    cin>>n>>f;
    for(i=0;i<n;++i)
    {
        cin>>k[i]>>l[i];
        fa=min(2*k[i],l[i])-min(k[i],l[i]);
        v.pb({fa,i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(i=0;i<f;++i)
    ans+=v[i].first;
    for(i=0;i<n;++i)
    ans+=min(l[i],k[i]);
    cout<<ans<<endl;
    return 0;
}