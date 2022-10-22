#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
#define MAXN 300005
#define L 1<<22
#define oo 1000005
map<int,int> M;
char _buf[L],*S,*T,c;
bool b;
int s[MAXN<<2],t[MAXN<<2],s1[MAXN],s2[MAXN],t1,t2,a[MAXN],n,P,Q,i,j,k,ans1=1,ans2=1;
void add(int R,int l,int r,int l1,int r1,int d)
{
    if(l1<=l&&r<=r1)
    {
        s[R]+=d;
        t[R]+=d;
        return;
    }
    int mid=l+r>>1;
    if(l1<=mid)add(R<<1,l,mid,l1,r1,d);
    if(r1>mid)add(R<<1|1,mid+1,r,l1,r1,d);
    t[R]=min(t[R<<1],t[R<<1|1])+s[R];
}
int ask(int R,int l,int r,int d)
{
    if(l==r)return l;
    int mid=l+r>>1;
    d-=s[R];
    if(t[R<<1]<=d)return ask(R<<1,l,mid,d);
    return ask(R<<1|1,mid+1,r,d);
}
inline char gc()
{
    if(S==T)return 0;
    return *S++;
}
void get(int &x)
{
    for(c=gc();(c<'0'||c>'9')&&c!='-';c=gc());
    if(c=='-')
    {
        b=1;
        c=gc();
    }
    else b=0;
    for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=x*10+(c^'0');
    if(b)x=-x;
}
int main()
{
    T=(S=_buf)+fread(_buf,1,L,stdin);
    get(n);
    get(Q);
    get(P);
    for(i=1;i<=n;i++)
    {
        get(a[i]);
        a[i]+=1000000001;
    }
    if(P)for(add(1,1,n,1,n,oo),i=1;i<=n;i++)
    {
        if(i!=1&&(a[i]-a[i-1])%P)
        {
            add(1,1,n,k+1,i-1,oo);
            k=i-1;
        }
        if(M[a[i]]>k)
        {
            add(1,1,n,k+1,M[a[i]],oo);
            k=M[a[i]];
        }
        M[a[i]]=i;
        while(t1&&a[s1[t1]]>a[i])
        {
            add(1,1,n,s1[t1-1]+1,s1[t1],a[s1[t1]]/P-a[i]/P);
            t1--;
        }
        while(t2&&a[s2[t2]]<a[i])
        {
            add(1,1,n,s2[t2-1]+1,s2[t2],a[i]/P-a[s2[t2]]/P);
            t2--;
        }
        s1[++t1]=s2[++t2]=i;
        add(1,1,n,i,i,i-oo);
        j=ask(1,1,n,i+Q);
        if(i+ans1>ans2+j)
        {
            ans1=j;
            ans2=i;
        }
    }
    else for(i=1;i<=n;i++)
    {
        if(i==1||a[i]!=a[i-1])k=i;
        if(i+ans1>ans2+k)
        {
            ans1=k;
            ans2=i;
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}