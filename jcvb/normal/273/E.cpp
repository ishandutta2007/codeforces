#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define mo 1000000007
using namespace std;
inline int mex(int a,int b){
    if(a && b)return 0;
    if(b==1 || a==1)return 2;
    return 1;
}
typedef long long ll;
struct node{int l,r;int v;};
node a[300],b[300],g[300];
int pa=0,qa=0,pb=0,qb=0,tot=0;
void expand(const node&t){
    if(pa!=qa && t.v==a[qa-1].v)a[qa-1].r=t.r*3+2;
    else a[qa++]=(node){t.l*3,t.r*3+2,t.v};
    if(pb!=qb && t.v==b[qb-1].v)b[qb-1].r=t.r&1?t.r/2*3+1:t.r/2*3;
    else b[qb++]=(node){t.l&1?t.l/2*3+1:t.l/2*3-1,t.r&1?t.r/2*3+1:t.r/2*3,t.v};
}
void pre(){
    g[++tot]=(node){1,2,0};
    expand(g[tot]);
    for (int i=3,r;i<=1000000000;i=r+1){
        while(a[pa].r<i)pa++;
        while(b[pb].r<i)pb++;
        r=min(a[pa].r,b[pb].r);
        g[++tot]=(node){i,r,mex(a[pa].v,b[pb].v)};
        expand(g[tot]);
    }
}
int f[3]={0};
int h[1005][4]={0};
int main(){
    pre();
    int n,p;scanf("%d%d",&n,&p);
    for (int i=1;i<=tot && g[i].l<=p;i++){
        g[i].r=min(g[i].r,p);
        f[g[i].v]=(f[g[i].v]+1ll*(p-g[i].l+p-g[i].r)*(g[i].r-g[i].l+1)/2)%mo;
    }
    h[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<4;j++)
            for (int k=0;k<3;k++)
                h[i][j]=(h[i][j]+1ll*h[i-1][j^k]*f[k])%mo;
    printf("%d\n",((h[n][1]+h[n][2])%mo+h[n][3])%mo);
    return 0;
}