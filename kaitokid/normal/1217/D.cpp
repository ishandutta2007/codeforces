#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool bl=false;
vector<pair<int,int> >a[5003];
int n,m;
int cl[5003];
bool vis[5003],vis2[5003];
void go(int wh)
{
    vis[wh]=true;
    vis2[wh]=true;
    for(int i=0;i<a[wh].size();i++)
    {
        if(vis2[a[wh][i].first]){bl=true;cl[a[wh][i].second]=2;continue;}
        if(!vis[a[wh][i].first]) go(a[wh][i].first);
    }
vis2[wh]=false;
}
int main()
{ios::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int u,v;
    cin>>u>>v;
    a[u].push_back(make_pair(v,i));
}
for(int i=1;i<=n;i++)if(!vis[i])go(i);
if(bl==false)
{
    cout<<1<<endl;

    for(int i=0;i<m;i++)cout<<"1 ";
    return 0;
}
cout<<2<<endl;
for(int i=0;i<m;i++)if(cl[i]==2)cout<<2<<" ";
else cout<<1<<" ";
    return 0;
}