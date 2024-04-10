#include<bits/stdc++.h>
using namespace std;
int n,a[1505],sum[1505];
int cot=0;
struct node
{
    int v,l,r;
}x[2500000];
vector<pair<int,int> >v[2];
bool cmp(node p1,node p2)
{
    if(p1.v==p2.v)
    {
        if(p1.r==p2.r)
            return p1.l<p2.l;
        return p1.r<p2.r;
    }
    return p1.v<p2.v;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
    {
        x[++cot].v=sum[j]-sum[i-1];
        x[cot].l=i;
        x[cot].r=j;
    }
    sort(x+1,x+1+cot,cmp);
    int ans=0,l,r;
    x[0].v=-1e9;
    for(int i=1;i<=cot;i++)
    {
        if(x[i].v!=x[i-1].v)
        {
            l=r=0;
            if(v[0].size()>v[1].size())
                v[1]=v[0];
            v[0].clear();
        }
        if(x[i].l>r)
        {
            v[0].push_back(make_pair(x[i].l,x[i].r));
            r=x[i].r;
        }
    }
    if(v[0].size()>v[1].size())
        v[1]=v[0];
    printf("%d\n",v[1].size());
    for(int i=0;i<v[1].size();i++)
        printf("%d %d\n",v[1][i].first,v[1][i].second);
}