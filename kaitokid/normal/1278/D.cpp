#include <bits/stdc++.h>

using namespace std;
int pr[500009],n,x,y,ans;
vector<pair<int,int> >v;
set<pair<int,int> >st;
int pa(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=pa(pr[x]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    set<pair<int,int> >::iterator it,it1,it2;
    for(int i=0;i<n;i++){pr[i]=i;cin>>x>>y;v.push_back(make_pair(x,y));}
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        it1=st.lower_bound(make_pair(v[i].first,0));
        it2=st.lower_bound(make_pair(v[i].second,0));
for(it=it1;it!=it2;it++)
{int u=(*it).second;
x=pa(i),y=pa(u);
if(x==y){cout<<"NO";return 0;}
ans++;
pr[x]=y;
}
st.insert(make_pair(v[i].second,i));
    }
    if(ans==n-1)cout<<"YES";
    else cout<<"NO";
    return 0;
}