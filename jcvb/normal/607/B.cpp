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
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
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
int mo=1000000007;
int inf=1061109567;
db eps=1e-6;
//ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

int n;
int a[555];
int f[555][555];
int main()
{
    gn(n);
    for (int i=1;i<=n;i++)gn(a[i]);

    memset(f,63,sizeof(f));
    for (int i=1;i<=n+1;i++)
        for (int j=0;j<i;j++)f[i][j]=1;

    for (int le=1;le<=n;le++)
        for (int i=1,j;j=i+le-1,j<=n;i++){
            for (int k=i;k<j;k++)f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            if(a[i]==a[j])f[i][j]=min(f[i][j],f[i+1][j-1]);
        }
    printf("%d\n",f[1][n]);
    return 0;
}