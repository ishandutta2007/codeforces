#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <LL,int> pli;

const int MAX=200005;

struct segment
{
    LL l,r;
}s[MAX];

struct bridge
{
    LL len;
    int id;
}a[MAX];

struct querry
{
    LL l,r;
    int id;
}q[MAX];

int ans[MAX];

priority_queue <pli,vector<pli>,greater<pli> > pq;

bool cmp1(querry a,querry b)
{
    return a.l!=b.l?a.l<b.l:a.r<b.r;
}

bool cmp2(bridge a,bridge b)
{
    return a.len<b.len;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%I64d%I64d",&s[i].l,&s[i].r);
    for (int i=1;i<n;i++)
    {
        q[i].l=s[i].l-s[i-1].r;
        q[i].r=s[i].r-s[i-1].l;
        q[i].id=i;
    }
    sort(q+1,q+n,cmp1);
    for (int i=0;i<m;i++)
    {
        scanf("%I64d",&a[i].len);
        a[i].id=i+1;
    }
    sort(a,a+m,cmp2);
    int h=1;
    for (int i=0;i<m;i++)
    {
        while (h<n&&q[h].l<=a[i].len)
        {
            pq.push(make_pair(q[h].r,q[h].id));
            h++;
        }
        while (!pq.empty())
        {
            pli x=pq.top();pq.pop();
            if (x.first<a[i].len) continue;
            ans[x.second]=a[i].id;
            break;
        }
    }
    for (int i=1;i<n;i++)
        if (!ans[i])
        {
            printf("No");
            return 0;
        }
    puts("Yes");
    for (int i=1;i<n;i++) printf("%d ",ans[i]);
    return 0;
}