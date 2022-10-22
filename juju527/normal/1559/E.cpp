#include<bits/stdc++.h>
using namespace std;
const int maxn=55,maxm=1e5+5,mod=998244353;
int n,m;
int l[maxn],r[maxn];
int f[2][maxm],s[2][maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
int len;
bool bj[maxm];
int p[maxm],mu[maxm];
void pre(){
    mu[1]=1;
    for(int i=2;i<=m;i++){
        if(!bj[i])p[++len]=i,mu[i]=mod-1;
        for(int j=1;i*p[j]<=m&&j<=len;j++){
            bj[i*p[j]]=1;
            mu[i*p[j]]=mod-mu[i];
            if(i%p[j]==0){mu[i*p[j]]=0;break;}
        }
    }
    return ;
}
int trans(int m,int d){
    f[0][0]=s[0][0]=1;
    for(int i=1;i<=m;i++)f[0][i]=0,s[0][i]=1;
    for(int i=1;i<=n;i++){
        int now=i&1,pre=now^1;
        int L=ceil(1.0*l[i]/d),R=r[i]/d;
        for(int j=0;j<=m;j++)s[now][j]=f[now][j]=0;
        for(int j=L;j<=m;j++){
            f[now][j]=sub(s[pre][j-L]-(j-R-1<0?0:s[pre][j-R-1]));
            s[now][j]=add(s[now][j-1]+f[now][j]);
        }
    }
    int res=0;
    for(int i=0;i<=m;i++)res=add(res+f[n&1][i]);
    return res;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)l[i]=read(),r[i]=read();
    pre();
    int res=0;
    for(int d=1;d<=m;d++)
        res=add(res+1ll*mu[d]*trans(m/d,d)%mod);
    printf("%d\n",res);
    return 0;
}