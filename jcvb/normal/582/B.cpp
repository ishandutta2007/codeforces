#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int n,t;
map<int,int>ma;
int a[105];
int tot=0;

struct node{
    int f[105][105];
}ini,zer;
int g[105];

node operator+(const node&a,const node&b){
    node c=zer;
    for (int i=1;i<=tot;i++)
        for (int j=i;j<=tot;j++){
            c.f[i][j]=max(c.f[i][j],a.f[i][j]);
            c.f[i][j]=max(c.f[i][j],b.f[i][j]);
        }
    for (int k=1;k<=tot;k++)
        for (int i=1;i<=k;i++)
            for (int j=k;j<=tot;j++)
                c.f[i][j]=max(c.f[i][j],a.f[i][k]+b.f[k][j]);
    return c;
}

node qui(int b){
    node ans=zer;
    do{
        if(b&1)ans=ans+ini;
        ini=ini+ini;
    }while(b>>=1);
    return ans;
}
node an;
int main()
{
    scanf("%d%d",&n,&t);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ma[a[i]];
    }
    for (map<int,int>::iterator it=ma.begin();it!=ma.end();it++)it->second=++tot;
    for (int i=1;i<=n;i++){
        a[i]=ma[a[i]];
    }

    for (int lo=1;lo<=tot;lo++){
        g[0]=0;
        for (int i=1;i<=n;i++){
            if(a[i]<lo)g[i]=0;
            else{
                g[i]=1;
                for (int j=1;j<i;j++)if(a[j]<=a[i])g[i]=max(g[i],g[j]+1);
            }
        }
        for (int i=1;i<=n;i++)if(a[i]>=lo)ini.f[lo][a[i]]=max(ini.f[lo][a[i]],g[i]);
    }
    an=qui(t);
    int ma=0;
    for (int i=1;i<=tot;i++)
        for (int j=i;j<=tot;j++)ma=max(ma,an.f[i][j]);
    printf("%d\n",ma);
    return 0;
}