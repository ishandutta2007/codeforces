#include<bits/stdc++.h>
using namespace std;
const int maxn=405,inf=0x3f3f3f3f;
char s[maxn];
int a[maxn][maxn];
int sl[maxn][maxn],sc[maxn][maxn];
int sum[maxn][maxn];
int z[maxn];
int suf[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
    T=read();
    while(T--){
        int n,m;
        n=read();m=read();
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);
            for(int j=1;j<=m;j++)a[i][j]=(s[j]=='1'),sl[i][j]=sl[i][j-1]+(1-a[i][j]),sc[i][j]=sc[i-1][j]+(1-a[i][j]);
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
        int res=inf;
        for(int l=1;l<=n;l++){
            for(int r=l+4;r<=n;r++){
                for(int i=1;i<=m;i++)z[i]=sc[r-1][i]-sc[l][i];
                suf[m+1]=inf;
                for(int i=m;i>=1;i--)
                    suf[i]=min(suf[i+1],z[i]+sl[l][i-1]+sl[r][i-1]+sum[r-1][i-1]-sum[l][i-1]);
                for(int i=1;i<=m-3;i++){
                    int val=z[i]-sl[l][i]-sl[r][i]-sum[r-1][i]+sum[l][i]+suf[i+3];
                    res=min(res,val);
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}