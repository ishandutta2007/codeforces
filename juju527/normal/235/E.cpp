#include<bits/stdc++.h>
using namespace std;
const int maxn=2005,mod=(1<<30);
int a,b,c;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){
    if(x>=mod)x-=mod;
    return x;
}
bool bj[maxn];
int len;
int p[maxn];
int mu[maxn];
int g[maxn][maxn],s[maxn][maxn];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
void pre(){
    mu[1]=1;
    for(int i=2;i<=c;i++){
        if(!bj[i]){p[++len]=i;mu[i]=mod-1;}
        for(int j=1;i*p[j]<=c&&j<=len;j++){
            bj[i*p[j]]=1;
            if(i%p[j]==0){mu[i*p[j]]=0;break;}
            mu[i*p[j]]=1ll*mu[i]*mu[p[j]]%mod;
        }
    }
    for(int i=1;i<=c;i++)
        for(int j=i;j<=c;j++)
            g[i][j]=g[j][i]=gcd(i,j);
    for(int i=1;i<=c;i++)
        for(int j=1;j<=c;j++)
            s[i][j]=s[i][j-1]+(g[i][j]==1);
    return ;
}
int main(){
    a=read();b=read();c=read();
    if(a>b)swap(a,b);if(b>c)swap(b,c);if(a>b)swap(a,b);
    pre();
    int ans=0;
    for(int d=1;d<=a;d++){
        int n=a/d,m=b/d;
        for(int z=1;z<=c;z++){
            if(g[z][d]>1)continue;
            int sum1=0,sum2=0;
            for(int l=1,r=0;l<=n;l=r+1){
                r=n/(n/l);
                sum1=add(sum1+1ll*(s[z][r]-s[z][l-1])*(n/l)%mod);
            }
            for(int l=1,r=0;l<=m;l=r+1){
                r=m/(m/l);
                sum2=add(sum2+1ll*(s[z][r]-s[z][l-1])*(m/l)%mod);
            }
            ans=add(ans+1ll*mu[d]*(c/z)%mod*sum1%mod*sum2%mod);
        }
    }
    printf("%d\n",ans);
    return 0;
}