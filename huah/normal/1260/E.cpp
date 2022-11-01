#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n,mn[20],a[300005];
priority_queue<int,vector<int>,greater<int> >q[20];
priority_queue<int>res;
int main()
{
    memset(mn,inf,sizeof(mn));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==-1)
            for(int j=i;j>=1;j--)
            a[j]=0;
    }
    int now=2,tot=1;
    for(int i=1;i<=n;i++)
    {
        if(i>=now) now*=2,tot++;
        q[tot].push(a[i]);
    }
    for(int i=1;i<=tot;i++)
    {
        res.push(q[i].top());
        q[i].pop();
        while(!q[i].empty()&&q[i].top()<res.top())
        {
            res.pop();res.push(q[i].top());q[i].pop();
        }
    }
    long long ans=0;
    while(!res.empty())
        ans+=res.top(),res.pop();
    printf("%lld\n",ans);
}