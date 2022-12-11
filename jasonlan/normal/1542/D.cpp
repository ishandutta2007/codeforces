#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=520,mod=998244353;
int n;
int f[maxn][maxn];
char s[maxn];
int op[maxn][3],rk[maxn],tnt;
bool IsIn[maxn];
int ans;
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
bool cmp(int x,int y){
    return op[x][1]<op[y][1];
}
void Does(int x){
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            f[i][j]=0;
    f[0][0]=1;
    for(int i=1;i<x;++i){
        if(op[i][0]==1){
            if(!IsIn[i]){
                for(int j=0;j<=n;++j)
                    f[i][j]=(f[i-1][j]<<1)%mod;
            }
            else{
                f[i][0]=f[i-1][0];
                for(int j=1;j<=n;++j)
                    f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
            }
        }
        else{
            f[i][0]=((f[i-1][0]<<1)%mod+f[i-1][1])%mod;
            for(int j=1;j<=n;++j)
                f[i][j]=(f[i-1][j]+f[i-1][j+1])%mod;
        }
    }
    for(int j=0;j<=n;++j)
        f[x][j]=f[x-1][j];
    for(int i=x+1;i<=n;++i){
        if(op[i][0]==1){
            if(!IsIn[i]){
                for(int j=0;j<=n;++j)
                    f[i][j]=(f[i-1][j]<<1)%mod;
            }
            else{
                f[i][0]=f[i-1][0];
                for(int j=1;j<=n;++j)
                    f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
            }
        }
        else{
            f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
            for(int j=1;j<=n;++j)
                f[i][j]=(f[i-1][j]+f[i-1][j+1])%mod;
        }
    }
    int cnt=0;
    for(int i=0;i<=n;++i)
        cnt=(cnt+f[n][i])%mod;
    ans=(ans+1ll*cnt*op[x][1]%mod)%mod;
}
void proc(){
    n=read();
    for(int i=1;i<=n;++i){
        scanf("%s",s);
        if(s[0]=='-')op[i][0]=-1;
        else{
            op[i][0]=1;
            op[i][1]=read();
            rk[++tnt]=i;
        }
    }
    sort(rk+1,rk+1+tnt,cmp);
    for(int i=1;i<=tnt;++i){
        Does(rk[i]);
        IsIn[rk[i]]=true;
    }
    printf("%d\n",ans);
}
int main(){
    int T=1;
    while(T--)proc();
    return 0;
}