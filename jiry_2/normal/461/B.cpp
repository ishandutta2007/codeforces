#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,x[110000],p[110000],len;
struct bian{
    int next,point;
}b[210000];
long long f[110000][2],g[110000],mo=1000000007;
void ade(int k1,int k2){
    len++; b[len].point=k2; b[len].next=p[k1]; p[k1]=len;
}
void treedp(int k){
    if (p[k]==0){
        f[k][x[k]]=1; return;
    }
    for (int i=p[k];i;i=b[i].next){int j=b[i].point; treedp(j);}
    if (x[k]==1){
        f[k][1]=1;
        for (int i=p[k];i;i=b[i].next){
            int j=b[i].point; f[k][1]=f[k][1]*(f[j][0]+f[j][1])%mo;
        }
        return;
    }
    f[k][0]=1; 
    for (int i=p[k];i;i=b[i].next){
        int j=b[i].point;
        f[k][1]=(f[k][1]*(f[j][0]+f[j][1])%mo+f[k][0]*f[j][1]%mo)%mo; 
        f[k][0]=f[k][0]*(f[j][0]+f[j][1])%mo;
    }
}
int main(){
    memset(g,0x00,sizeof g);
    scanf("%d",&n); len=0; memset(p,0x00,sizeof p);
    memset(f,0x00,sizeof f);
    for (int i=2;i<=n;i++){
        int k1; scanf("%d",&k1); ade(k1+1,i);
    }
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    treedp(1); cout<<f[1][1]<<endl;
    return 0;
}