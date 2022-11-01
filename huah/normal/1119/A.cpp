#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int x,id;
}a[300005];
bool cmp(node p1,node p2)
{
    if(p1.x==p2.x) return p1.id<p2.id;
    return p1.x<p2.x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].x),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    int ans=0,i=1,ma=a[1].id,mi=a[1].id,x,y;
    for(i=2;i<=n;i++)
    {
        if(a[i].x!=a[1].x) break;
        //cout<<a[i].id<<endl;
        ma=max(ma,a[i].id);
        mi=min(mi,a[i].id);
    }
    x=1e9,y=0;
    for(;i<=n;i++)
    {
        //cout<<a[i].id<<' '<<ma<<' '<<mi<<endl;
        if(a[i].x!=a[i-1].x)
        {
            ma=max(ma,y);
            mi=min(mi,x);
            x=a[i].id,y=a[i].id;
        }
        ans=max(max(ans,abs(a[i].id-mi)),abs(a[i].id-ma));
        x=min(x,a[i].id);
        y=max(y,a[i].id);
    }
    cout<<ans<<endl;
}