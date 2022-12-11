#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int maxn=401000,maxk=23;
int n,k;
int a[maxn],b[maxn];
int R[maxn][maxk],f[maxn][maxk];
int vis[10000100];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void Proc(){
    n=read();k=read();
    for(int i=1,x;i<=n;++i){
        x=a[i]=read();
        b[i]=1;
        for(int j=2;j*j<=x;++j){
            if(x%j==0){
                int c=0;
                while(x%j==0)x/=j,++c;
                if(c&1)b[i]*=j;
            }
        }
        b[i]*=x;
    }
    for(int lim=0;lim<=k;++lim){
        int cnt=0;
        for(int i=1,j=1;i<=n;++i){
            ++vis[b[i]];
            if(vis[b[i]]>=2)++cnt;
            if(cnt>lim){
                while(cnt>lim){
                    if(vis[b[j]]>=2)--cnt;
                    --vis[b[j]];
                    ++j;
                }
            }
            R[i][lim]=j;
        }
        for(int i=1;i<=n;++i)
            vis[b[i]]=0;
    }
    for(int i=0;i<=k;++i)
        for(int j=0;j<=n;++j)
            f[j][i]=0x3f3f3f3f;
    f[0][0]=0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=k;++j)
            for(int x=0;x<=j;++x)
                f[i][j]=min(f[i][j],f[R[i][x]-1][j-x]+1);
    int ans=0x3f3f3f3f;
    for(int i=0;i<=k;++i)
        ans=min(ans,f[n][i]);
    printf("%d\n",ans);
}
int main(){
    int T=read();
    while(T--)Proc();
    return 0;
}