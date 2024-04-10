#include<bits/stdc++.h>
using namespace std;
int n,k,d[200005],dd[200005];
map<pair<int,int>,int>mp;
struct node
{
    int u,v;
}e[200005];
vector<int>v[200005];
queue<pair<int,int> >q;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[i].u=x;e[i].v=y;
        d[x]++;d[y]++;
        dd[x]++;dd[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sort(dd+1,dd+1+n);
    reverse(dd+1,dd+1+n);
    k=dd[k+1];
    printf("%d\n",k);
    q.push(make_pair(1,0));
    while(!q.empty())
    {
        pair<int,int>now=q.front();q.pop();
        int t=1,x=now.first,y=now.second;
        for(int i=0;i<v[x].size();i++)
        {
            if(mp[make_pair(x,v[x][i])]) continue;
            if(t==y) t++;
            t=min(t,k);
            mp[make_pair(x,v[x][i])]=mp[make_pair(v[x][i],x)]=t;
            q.push(make_pair(v[x][i],t));
            t++;
        }
    }
    for(int i=1;i<n;i++)
        printf(i==n-1?"%d\n":"%d ",mp[make_pair(e[i].u,e[i].v)]);
}