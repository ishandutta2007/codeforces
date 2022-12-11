#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
    int next,point;
}b[7000];
int p[4000],n,len,pd[4000],x[4000],s[4000],head,bo[4000],d[4000],u[4000];
double a[4000];
long double ans;
void ade(int k1,int k2){
    b[++len]=(bian){p[k1],k2}; p[k1]=len; 
}
void add(int k1,int k2){
    ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
    if (bo[k1]){
        while (s[head+1]!=k1){
            x[++len]=s[head]; d[x[len]]=len; pd[s[head]]=1; head--;
        }
        return;
    }
    bo[k1]=1; s[++head]=k1;
    for (int i=p[k1];i!=-1;i=b[i].next){
        int j=b[i].point; if ((i^1)!=k2) dfs(j,i); if (len) return;
    }
    head--;
}
void dfs2(int k1,int k2,int k3,int k4){
    d[k1]=k3; u[k1]=k4;
    for (int i=p[k1];i!=-1;i=b[i].next){
        int j=b[i].point; if (j!=k2&&pd[j]==0) dfs2(j,k1,k3,k4+1);
    }
}
void dfs3(int k1,int k2,int k3){
    ans+=a[k3]; 
    for (int i=p[k1];i!=-1;i=b[i].next){
        int j=b[i].point; if (pd[j]==0&&j!=k2) dfs3(j,k1,k3+1);
    }
}
int main(){
    scanf("%d",&n); len=-1; memset(p,0xff,sizeof p);
    for (int i=1;i<=n;i++) a[i]=1.0/i;
    for (int i=1;i<=n;i++){int k1,k2; scanf("%d%d",&k1,&k2); k1++; k2++; add(k1,k2);} 
    len=0; dfs(1,-100); for (int i=1;i<=n;i++) if (pd[i]) dfs2(i,0,d[i],0); ans=0;
    for (int i=1;i<=n;i++){pd[x[d[i]]]=0; dfs3(i,0,1); pd[x[d[i]]]=1;}
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (d[i]!=d[j]){
                int k1=u[i]+u[j],k2=abs(d[i]-d[j])+1,k3=len-k2+2; ans+=a[k1+k2]+a[k1+k3]-a[k1+len];
            }
    printf("%.11lf",(double)ans); return 0;
}