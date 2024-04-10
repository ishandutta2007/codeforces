#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


int c[2005][2005];
int N=2000;
int a[2222];
int k;
int main()
{
    c[0][0]=1;
    for (int i=1;i<=N;i++){
        c[i][0]=1;
        for (int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
    }
    scanf("%d",&k);
    int su=0;
    for (int i=1;i<=k;i++)scanf("%d",&a[i]),su+=a[i];
    int ans=1;
    for (int i=k;i>=1;i--){
        ans=1ll*ans*c[su-1][a[i]-1]%mo;
        su-=a[i];
    }
    printf("%d\n",ans);
    return 0;
}