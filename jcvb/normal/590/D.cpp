#include<cstdio>
#include<algorithm>
#include<cassert>
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
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;

int f[155][155*155];
int a[155];
int n,k,s;
int main()
{
    scanf("%d%d%d",&n,&k,&s);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(f,63,sizeof(f));
    f[0][0]=0;
    int ma=n*(n-1)/2;
    for (int i=1;i<=n;i++)
        for (int k=i;k>=1;k--)
            for (int j=i*(i-1)/2;j>=i-1;j--){
                f[k][j]=min(f[k][j],f[k-1][j-(i-1)]+a[i]);
            }
    int mi=1000000000;
    for (int i=0;i<=ma;i++)if(i-(k-1)*k/2<=s)mi=min(mi,f[k][i]);
    printf("%d\n",mi);
    return 0;
}