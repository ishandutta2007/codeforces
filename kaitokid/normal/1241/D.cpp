#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int fr[300009],en[300009],x,n;
vector<pair<int,int> >v;
int main()
{
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)fr[i]=-1,en[i]=-1;
        for(int i=0;i<n;i++){cin>>x;if(fr[x]==-1){fr[x]=i;en[x]=i;}else en[x]=i;}
        v.clear();
        for(int i=1;i<=n;i++)if(fr[i]!=-1)v.push_back(make_pair(fr[i],en[i]));
        int ans=1,u=1;
        for(int i=1;i<v.size();i++)
        {if(v[i].first>v[i-1].second)u++;else u=1;ans=max(ans,u);}
        cout<<v.size()-ans<<"\n";

    }
    return 0;
}