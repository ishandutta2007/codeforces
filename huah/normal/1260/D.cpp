#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int m,n,k,t,a[N],b[N];
vector<pair<int,int> >v[N];
bool judge(int mid)
{
    int s=a[mid],res=0;
    int now=0;
    while(now<=n)
    {
        int nex=now+1,r=now;
        for(int i=0;i<v[nex].size();i++)
            if(v[nex][i].first>s)
            r=max(r,v[nex][i].second);
            else break;
        if(r==now)
            res++,now++;
        else
        {
            for(int j=nex;j<=r;j++)
                for(int k=0;k<v[j].size();k++)
                    if(v[j][k].first>s)
                    r=max(r,v[j][k].second);
                else break;
            res+=3*(r-now);
            now=r;
        }
    }
    return res<=t;
}
int main()
{
    scanf("%d%d%d%d",&m,&n,&k,&t);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+m);reverse(a+1,a+1+m);
    while(k--)
    {
        int l,r,d;
        scanf("%d%d%d",&l,&r,&d);
        v[l].push_back({d,r});
    }
    for(int i=0;i<=n;i++) sort(v[i].begin(),v[i].end()),reverse(v[i].begin(),v[i].end());
    int l=1,r=m,ans=0;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(judge(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
}