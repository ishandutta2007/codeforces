#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct bian{
    int next,point,f;
}b[200000];
int p[50000],n,m,len,dst[50000],pd[50000],totpoint,inf=1e9,big=1e8,g,x[50000];
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
int main(){
    scanf("%d%d%d",&n,&m,&g); totpoint=n+1; int tot=0,now=totpoint; 
    len=-1; memset(p,0xff,sizeof p);
    for (int i=1;i<=n;i++) scanf("%d",&pd[i]);
    for (int i=1;i<=n;i++){
        int k1; scanf("%d",&k1);
        if (pd[i]==0) add(i,totpoint,k1); else add(0,i,k1);
    }
    for (;m;m--){
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); tot+=k2; now++;
        for (;k3;k3--){
            int k4; scanf("%d",&k4);
            if (k1==0) add(k4,now,inf);
            if (k1==1) add(now,k4,inf);
        }
        int k4; scanf("%d",&k4); if (k4==1) k2+=g; if (k1==0) add(now,totpoint,k2); else add(0,now,k2);
    }
    cout<<tot-dinic()<<endl; return 0;
}