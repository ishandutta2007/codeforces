//Code By juju527.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2005,mod=1e9+7;
char a[maxn],b[maxn];
int f[maxn][2*maxn],g[maxn][2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
int main(){
    int T;
    T=read();
    while(T--){
        int n;
        n=read();
        scanf("%s",a+1);scanf("%s",b+1);
        for(int i=1;i<=n;i+=2){
            if(a[i]!='?')a[i]=((a[i]-'0')^1)+'0';
            if(b[i]!='?')b[i]=((b[i]-'0')^1)+'0';
        }
        for(int i=0;i<=n+1;i++)for(int s=0;s<=2*n;s++)f[i][s]=g[i][s]=0;
        f[0][n]=1;
        for(int i=0;i<n;i++){
            for(int s=0;s<=2*n;s++){
                if(!f[i][s])continue;
                for(int v=0;v<=1;v++){
                    if(a[i+1]!='?'&&a[i+1]-'0'!=v)continue;
                    for(int w=0;w<=1;w++){
                        if(b[i+1]!='?'&&b[i+1]-'0'!=w)continue;
                        f[i+1][s+v-w]=add(f[i+1][s+v-w]+f[i][s]);
                    }
                }
            }
        }
        g[n+1][n]=1;
        for(int i=n+1;i>1;i--){
            for(int s=0;s<=2*n;s++){
                if(!g[i][s])continue;
                for(int v=0;v<=1;v++){
                    if(a[i-1]!='?'&&a[i-1]-'0'!=v)continue;
                    for(int w=0;w<=1;w++){
                        if(b[i-1]!='?'&&b[i-1]-'0'!=w)continue;
                        g[i-1][s+v-w]=add(g[i-1][s+v-w]+g[i][s]);
                    }
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++)
            for(int s=0;s<=2*n;s++)
                res=add(res+1ll*abs(s-n)*f[i][s]%mod*g[i+1][2*n-s]%mod);
        printf("%d\n",res);
    }
    return 0;
}