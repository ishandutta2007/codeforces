#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
const int N=3e5+5,mod=998244353;
int n,m,ans[N];
struct node
{
    int x,id;
    char c;
    bool operator<(const node&o)const
    {
        return x<o.x;
    }
}a[N];
int cal(int x,int y)
{
    if(x>y) swap(x,y);
    if(a[x].c=='R'&&a[y].c=='R')
        return m-a[y].x+(a[y].x-a[x].x)/2;
    if(a[x].c=='L'&&a[y].c=='L')
        return a[x].x+(a[y].x-a[x].x)/2;
    if(a[x].c=='R'&&a[y].c=='L')
        return (a[y].x-a[x].x)/2;
    int ans;
    int xx=a[x].x,yy=a[y].x;
    if(xx<=(m-yy))
    {
        ans=xx;
        yy+=xx;xx=0;
        ans+=m-yy+(yy-xx)/2;
    }
    else
    {
        ans=m-yy;
        yy=m;xx-=ans;
        ans+=xx+(yy-xx)/2;
    }
    return ans;
}
int main()
{
    int t;sc(t);
    while(t--)
    {
        sc(n,m);
        rep(i,1,n) sc(a[i].x),ans[i]=-1,a[i].id=i;
        rep(i,1,n) cin>>a[i].c;
        sort(a+1,a+1+n);
        stack<int>st;
        rep(i,1,n)
        if(a[i].x&1)
        {
            if(st.empty()) st.push(i);
            else if(a[i].c=='L')
            {
                ans[a[st.top()].id]=ans[a[i].id]=cal(st.top(),i);
                st.pop();
            }
            else st.push(i);
        }
        while(st.size()>=2)
        {
            int x=st.top();st.pop();
            int y=st.top();st.pop();
            ans[a[x].id]=ans[a[y].id]=cal(x,y);
        }
        if(st.size()) st.pop();
        rep(i,1,n)
        if(a[i].x%2==0)
        {
            if(st.empty()) st.push(i);
            else if(a[i].c=='L')
            {
                ans[a[st.top()].id]=ans[a[i].id]=cal(st.top(),i);
                st.pop();
            }
            else st.push(i);
        }
        while(st.size()>=2)
        {
            int x=st.top();st.pop();
            int y=st.top();st.pop();
            ans[a[x].id]=ans[a[y].id]=cal(x,y);
        }
        if(st.size()) st.pop();
        rep(i,1,n)
        printf(i==n?"%d\n":"%d ",ans[i]);
    }
}