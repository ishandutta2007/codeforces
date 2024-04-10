#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],t[N<<2],bk1[N],bk2[N];
char s[N];
void build(int l,int r,int k)
{
    if(l==r){t[k]=1;return;}
    int m=l+r>>1;
    build(l,m,k<<1);build(m+1,r,k<<1|1);
    t[k]=t[k<<1]+t[k<<1|1];
}
int querymx(int l,int r,int k,int x)
{
    t[k]--;
    if(l==r) return l;
    int m=l+r>>1;
    if(t[k<<1|1]>=x) return querymx(m+1,r,k<<1|1,x);
    return querymx(l,m,k<<1,x-t[k<<1|1]);
}
int querymn(int l,int r,int k,int x)
{
    t[k]--;
    if(l==r) return l;
    int m=l+r>>1;
    if(t[k<<1]>=x) return querymn(l,m,k<<1,x);
    return querymn(m+1,r,k<<1|1,x-t[k<<1]);
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        build(1,n,1);
        bk1[n]=bk2[n]=0;
        for(int i=n-1;i>=1;i--)
        {
            if(s[i]=='<'&&s[i+1]!='<') bk1[i]=1;
            if(s[i]=='<'&&s[i+1]=='<') bk1[i]=bk1[i+1]+1;
            if(s[i]=='>') bk1[i]=bk1[i+1];
            if(s[i]=='>'&&s[i+1]!='>') bk2[i]=1;
            if(s[i]=='>'&&s[i+1]=='>') bk2[i]=bk2[i+1]+1;
            if(s[i]=='<') bk2[i]=bk2[i+1];
        }
        for(int i=1;i<=n;i++)
        {
            int k=bk1[i]+1;
            if(s[i-1]=='<'&&s[i]!='<') k=1;
            a[i]=querymx(1,n,1,k);
        }
        for(int i=1;i<=n;i++)
            printf(i==n?"%d\n":"%d ",a[i]);
        build(1,n,1);
        for(int i=1;i<=n;i++)
        {
            int k=bk2[i]+1;
            if(s[i-1]=='>'&&s[i]!='>') k=1;
            a[i]=querymn(1,n,1,k);
        }
        for(int i=1;i<=n;i++)
            printf(i==n?"%d\n":"%d ",a[i]);
    }
}