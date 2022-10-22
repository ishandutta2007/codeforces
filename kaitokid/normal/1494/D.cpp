#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<int,pair<int,int> > > v;
int pr[500009],c[1000000];
vector<pair<int,int> >ed;
int pa(int x)
{
    if(pr[x]==x)return x;
    return pr[x]=pa(pr[x]);
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
    pr[i]=i;
    for(int j=1;j<=n;j++)
    {
        int x;
        cin>>x;
        if(i==j)c[i]=x;
        else v.push_back({x,{i,j}});
    }

}
sort(v.begin(),v.end());
int id=n;
for(int i=0;i<v.size();i++)
{

    int x=pa(v[i].second.first);
    int y=pa(v[i].second.second);
    int r=v[i].first;
if(x==y)continue;
 if(c[x]==r)
 {
     ed.push_back({y,x});
     pr[y]=x;
     continue;

 }
 if(c[y]==r)
 {
     ed.push_back({x,y});
     pr[x]=y;
     continue;

 }
    id++;
    pr[id]=id;
    ed.push_back({x,id});
    ed.push_back({y,id});

    c[id]=r;
    pr[x]=id;
    pr[y]=id;


}
cout<<id<<endl;
int mx=0,w=0;
for(int i=1;i<=id;i++)
    {cout<<c[i]<<" ";
if(c[i]>mx){mx=c[i];w=i;}}
cout<<endl<<w<<endl;
for(int i=0;i<ed.size();i++)
    cout<<ed[i].first<<" "<<ed[i].second<<endl;
   return 0;
}