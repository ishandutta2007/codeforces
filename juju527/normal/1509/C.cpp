#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2005;
struct node{
    int id,data;
    bool operator <(node i)const{
        return data<i.data;
    }
}a[maxn];
int val[maxn];
int num[maxn],vnum[maxn];
int f[maxn][maxn];
int g1[maxn],g2[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
signed main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++)a[i]=(node){i,read()};
    sort(a+1,a+n+1);
    int w=0;
    for(int i=1;i<=n;i++){
        if(a[i].data>a[i-1].data)val[++w]=a[i].data;
        num[w]++;
    }
    for(int i=1;i<=w;i++)vnum[i]=vnum[i-1]+1ll*val[i]*num[i];
    for(int i=1;i<=w;i++)num[i]+=num[i-1];
    memset(f,0x3f,sizeof(f));
    memset(g1,0x3f,sizeof(g1));memset(g2,0x3f,sizeof(g2));
    for(int i=1;i<=w;i++)f[i][i]=0;
    for(int i=1;i<=w;i++){
        for(int j=i;j>=1;j--){
            if(i^j)f[i][j]=min(f[i][j],min(g1[j]+vnum[i]-val[j]*num[i],g2[i]+vnum[j-1]-val[i]*num[j-1]));
            g1[j]=min(g1[j],f[i][j]+val[j]*num[i]-vnum[i]);
            g2[i]=min(g2[i],f[i][j]+val[i]*num[j-1]-vnum[j-1]);
        }
    }
    printf("%lld",f[w][1]);
    return 0;
}