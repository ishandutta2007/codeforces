#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=500010,mod=19940417;
int n,m,ma;
int f[21][maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int main(){
    n=read();m=read();
    for(int i=1,l,r;i<=n;++i){
        l=read();r=read();
        f[0][l]=max(f[0][l],r);
        ma=max(ma,r);
    }
    n=ma;
    for(int i=0;i<=n;++i)
        f[0][i]=max(f[0][i],f[0][i-1]);
    for(int i=1;i<=20;++i)
        for(int j=0;j<=n;++j)
            f[i][j]=f[i-1][f[i-1][j]];
    for(int i=1,l,r,cnt;i<=m;++i){
        l=read();r=read();
        cnt=0;
        for(int i=20;~i;--i)
            if(f[i][l]<r){
                cnt|=1<<i;l=f[i][l];
            }
        if(f[0][l]>=r)printf("%d\n",cnt+1);
        else puts("-1");
    }
    return 0;
}