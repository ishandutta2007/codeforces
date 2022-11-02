#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,m;
LL ans,l,ls;
struct data
{
    LL s,e,t;
    data(LL a=0,LL b=0,LL c=0):s(a),e(b),t(c){}
}a[200010];
bool operator < (const data &x,const data &y)
{
    return x.t>y.t;
}
priority_queue<data> q;

bool cmp(data x,data y)
{
    if (x.s==y.s) return x.t<y.t;
    return x.s<y.s;
}

void work(LL t)
{
    if (l>=t) return ;
    while(!q.empty())
    {
        auto x=q.top();
        if (x.e<=l)
        {
            q.pop();
        }
        else if (x.e>=t)
        {
            ans+=(t-l)/x.t;
            l+=(t-l)/x.t*x.t;
            ls=l-x.t;
            break;
        }
        else
        {
            ans+=(x.e-l)/x.t;
            l+=(x.e-l)/x.t*x.t;
            ls=l-x.t;
            q.pop();
        }
    }
    while(!q.empty())
    {
        auto x=q.top();
        if (l>=x.s&&l+x.t<=x.e) break;
        else q.pop();
    }
    if (!q.empty())
    {
        ans++;
        ls=l;
        l+=q.top().t;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld%lld%lld",&a[i].s,&a[i].e,&a[i].t);
    sort(a+1,a+1+n,cmp);
    ans=0;
    for (int i=1;i<=n;i++)
    {
        work(a[i].s);
        if (a[i].s>l)
        {
            ans++;
            ls=a[i].s;
            l=a[i].s+a[i].t;
        }
        else if (a[i].s+a[i].t<l)
        {
            l=a[i].s+a[i].t;
            ls=a[i].s;
        }
        q.push(data(a[i].s,a[i].e,a[i].t));
    }
    while(!q.empty())
    {
        auto x=q.top();q.pop();
        if (x.e<=l) continue;
        ans+=(x.e-l)/x.t;
        l+=(x.e-l)/x.t*x.t;
    }
    printf("%lld\n",ans);
    return 0;
}