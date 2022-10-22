#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int mod;
int c[maxn][maxn];
int f[maxn][maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
int main(){
    int n,m,k;
    n=read();m=read();k=read();mod=read();
    c[0][0]=1;
    for(int i=1;i<=n;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=add(c[i-1][j]+c[i-1][j-1]);
    }
    for(int j=0;j<=m;j++)f[0][j][0]=f[1][j][0]=1;
    f[1][1][1]=1;f[1][1][0]=0;
    int fc=1;
    for(int i=2;i<=n;i++){
        int lim1=min(i,m),lim2=min(i,k);
        f[i][0][0]=(fc=1ll*fc*i%mod);for(int j=i+1;j<=m;j++)f[i][j][0]=fc;
        for(int j=1;j<=lim1;j++){
            for(int l=0;l<=lim2;l++){
                int lim3=l-(j==1);
                for(int p=1;p<=i;p++){
                    int sum=0;
                    for(int x=0;x<=lim3;x++){
                        if(!f[p-1][j-1][x]||!f[i-p][j-1][lim3-x])continue;
                        sum=add(sum+1ll*f[p-1][j-1][x]*f[i-p][j-1][lim3-x]%mod);
                    }
                    f[i][j][l]=add(f[i][j][l]+1ll*sum*c[i-1][p-1]%mod);
                }
            }
        }
    }
    printf("%d\n",f[n][m][k]);
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    return 0;
}