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
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


int n;
int f[4444][2];
int c[4444][4444];
int main()
{
    scanf("%d",&n);
    c[0][0]=1;
    for (int i=1;i<=n;i++){
        c[i][0]=1;
        for (int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
        }
    }
    f[0][0]=1;
    for (int i=1;i<=n;i++){
        for (int k=1;k<=i;k++){
            f[i][0]=(f[i][0]+1ll*c[i-1][k-1]*f[i-k][0])%mo;
            f[i][1]=(f[i][1]+1ll*c[i-1][k-1]*f[i-k][1])%mo;
        }
        f[i][1]=(0ll+f[i][1]+f[i-1][0]+f[i-1][1])%mo;
    }
    printf("%d\n",f[n][1]);
    return 0;
}