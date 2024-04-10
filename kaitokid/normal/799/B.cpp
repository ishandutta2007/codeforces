#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
pair<int,pair<int,int> > p[200009];
int ans[200009];
queue <int>g[4];
int main()
{ios::sync_with_stdio(0);
memset(ans,-1,sizeof ans);
int n,m;
cin>>n;
for(int i=0;i<n;i++)
cin>>p[i].first;
for(int i=0;i<n;i++)
cin>> p[i].second.first;
for(int i=0;i<n;i++)
cin>>p[i].second.second;
sort(p,p+n);
cin>>m;
int x;
for(int i=0;i<m;i++)
{cin>>x;
g[x].push(i);
}
for(int i=0;i<n;i++)
{
int k1=p[i].second.first;
int k2=p[i].second.second;
int y=p[i].first;
int h1=200001,h2=200001;
if(g[k1].size()>0)h1=g[k1].front();
if(g[k2].size()>0)h2=g[k2].front();
if(h1<=200000&&h1<h2){ans[h1]=y;g[k1].pop();continue;}
if(h2<=200000){ans[h2]=y;g[k2].pop();continue;}
}
for(int i=0;i<m;i++)
cout<<ans[i]<<" ";
return 0;}