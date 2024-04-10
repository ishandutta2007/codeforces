#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node
{
    ll t,l,r;
    bool operator<(const node&o)const
    {
        return t<o.t;
    }
}a[N];
int n,m;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ll l=m,r=m,now=0;
        for(int i=1;i<=n;i++)
            scanf("%lld%lld%lld",&a[i].t,&a[i].l,&a[i].r);
        sort(a+1,a+1+n);
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            l-=a[i].t-now;
            r+=a[i].t-now;
            now=a[i].t;
            if(r<a[i].l||l>a[i].r)
                {flag=false;break;}
            l=max(l,a[i].l);
            r=min(r,a[i].r);
        }
        printf(flag?"YES\n":"NO\n");
    }
}