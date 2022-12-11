#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
    int next,point,f;
}b[1000];
int p[220],n,m,x[220],s[110000],num,A[110][2],dst[220],totpoint,pd[220],len,inf=1e8,w[220];
int findnum(int k1,int k2){
    int ans=0;
    while (k1%k2==0){ans++; k1=k1/k2;}
    return ans;
}
void ade(int k1,int k2,int k3)
{
    len++; b[len].point=k2; b[len].next=p[k1]; b[len].f=k3; p[k1]=len;
}
void add(int k1,int k2,int k3)
{
    ade(k1,k2,k3); ade(k2,k1,0);
}
bool bfs()
{
    int head=1,now=0,i,j;
    memset(dst,0xff,sizeof dst);
    memset(pd,0x00,sizeof pd);
    x[1]=0; pd[0]=1; dst[0]=0;
    while (head>now)
    {
        now++; i=p[x[now]];
        while (i!=-1)
        {
            j=b[i].point;
            if ((b[i].f)&&(!pd[j]))
            {
                pd[j]=1; dst[j]=dst[x[now]]+1;
                if (j==totpoint)
                {
                    return 1;
                }
                head++; x[head]=j;
            }
            i=b[i].next;
        }
    }
    return pd[totpoint];
}
int change(int k1,int k2)
{
    if ((k1==totpoint)||(k2==0)) return k2;
    int num=0,k,i,j;
    i=p[k1];
    while (i!=-1)
    {
        j=b[i].point;
        if ((b[i].f)&&(dst[k1]+1==dst[j]))
        {
            k=change(j,min(k2,b[i].f));
            k2=k2-k; num+=k;
            b[i].f=b[i].f-k; b[i^1].f+=k;
            if (k2==0)
            {
                break;
            }
        }
        i=b[i].next;
    }
    if (!num)
    {
        dst[k1]=-1;
    }
    return num;
}
int dinic(){
    int now=0; while (bfs()) now+=change(0,inf); return now;
}
int find(int k){
    len=-1; memset(p,0xff,sizeof p);
    for (int i=1;i<=m;i++)
        if (A[i][0]%2==0) add(A[i][0],A[i][1],inf); else add(A[i][1],A[i][0],inf);
    for (int i=1;i<=n;i++){
        int k1=findnum(w[i],k);
        if (i%2==0) add(0,i,k1); else add(i,n+1,k1);
    }
    return dinic();
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    num=0;
    for (int i=1;i<=m;i++) scanf("%d%d",&A[i][0],&A[i][1]);
    for (int i=1;i<=n;i++){
        int k1=w[i];
        for (int j=2;1ll*j*j<=k1;j++){
            if (k1%j==0){
                s[++num]=j; while (k1%j==0) k1/=j;
            }
        }
        if (k1>1) s[++num]=k1;
    }
    sort(s+1,s+num+1); totpoint=n+1; int ans=0;
    for (int i=1;i<=num;i++)
        if (s[i]!=s[i-1])ans+=find(s[i]);
    cout<<ans<<endl; return 0;
}