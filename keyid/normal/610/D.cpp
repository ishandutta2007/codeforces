#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

struct segment
{
    int k,l,r;
}s1[MAXN],s2[MAXN];

struct operation
{
    int k,x,d;
}op[MAXN*2];

int n,c1,c2,nc,num[MAXN*4],C[MAXN*4];

bool cmp1(const segment &a,const segment &b)
{
    return a.k!=b.k?a.k<b.k:a.l!=b.l?a.l<b.l:a.r>b.r;
}

bool cmp2(const operation &a,const operation &b)
{
    return a.k<b.k;
}

inline void update(int x,int d)
{
    while (x<=nc)
    {
        C[x]+=d;
        x+=x&-x;
    }
}

inline int sum(int x)
{
    int ret=0;
    while (x)
    {
        ret+=C[x];
        x-=x&-x;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        num[nc++]=x1;
        num[nc++]=y1;
        num[nc++]=x2;
        num[nc++]=y2;
        if (x1==x2)
        {
            if (y1>y2) swap(y1,y2);
            s1[c1++]=(segment){x1,y1,y2};
        }
        else if (y1==y2)
        {
            if (x1>x2) swap(x1,x2);
            s2[c2++]=(segment){y1,x1,x2};
        }
    }
    sort(num,num+nc);
    nc=unique(num,num+nc)-num;
    sort(s1,s1+c1,cmp1);
    LL ans=0;
    int rc1=0;
    for (int i=0;i<c1;i++)
    {
        int j,begin=s1[i].l,last=s1[i].r;
        for (j=i;j<c1&&s1[j].k==s1[i].k;j++)
        {
            if (s1[j].l<=last) last=max(last,s1[j].r);
            else
            {
                s1[rc1++]=(segment){s1[i].k,begin,last};
                ans+=last-begin+1;
                begin=s1[j].l;
                last=s1[j].r;
            }
        }
        s1[rc1++]=(segment){s1[i].k,begin,last};
        ans+=last-begin+1;
        i=j-1;
    }
    c1=rc1;
    for (int i=0;i<c1;i++)
    {
        s1[i].k=upper_bound(num,num+nc,s1[i].k)-num;
        s1[i].l=upper_bound(num,num+nc,s1[i].l)-num;
        s1[i].r=upper_bound(num,num+nc,s1[i].r)-num;
    }
    sort(s2,s2+c2,cmp1);
    int rc2=0;
    for (int i=0;i<c2;i++)
    {
        int j,begin=s2[i].l,last=s2[i].r;
        for (j=i;j<c2&&s2[j].k==s2[i].k;j++)
        {
            if (s2[j].l<=last) last=max(last,s2[j].r);
            else
            {
                s2[rc2++]=(segment){s2[i].k,begin,last};
                ans+=last-begin+1;
                begin=s2[j].l;
                last=s2[j].r;
            }
        }
        s2[rc2++]=(segment){s2[i].k,begin,last};
        ans+=last-begin+1;
        i=j-1;
    }
    c2=rc2;
    for (int i=0;i<c2;i++)
    {
        s2[i].k=upper_bound(num,num+nc,s2[i].k)-num;
        s2[i].l=upper_bound(num,num+nc,s2[i].l)-num;
        s2[i].r=upper_bound(num,num+nc,s2[i].r)-num;
    }
    int cop=0;
    for (int i=0;i<c2;i++)
    {
        op[cop++]=(operation){s2[i].l,s2[i].k,1};
        op[cop++]=(operation){s2[i].r+1,s2[i].k,-1};
    }
    sort(op,op+cop,cmp2);
    int head=0;
    for (int i=0;i<c1;i++)
    {
        while (head<cop&&op[head].k<=s1[i].k)
        {
            update(op[head].x,op[head].d);
            head++;
        }
        ans-=sum(s1[i].r)-sum(s1[i].l-1);
    }
    printf("%I64d",ans);
    return 0;
}