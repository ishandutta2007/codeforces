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
const int inf=1061109567;
//const ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

int n,m;
int x[111];
db f[2][105*1005]={0};

inline void ad(db*a,int lef,int rig,db val){
    a[lef]+=val;
    a[rig+1]-=val;
}
int main()
{
    gn(n);
    gn(m);
    if(m==1){
        printf("%.15lf\n",1.0);
        return 0;
    }
    int su=0;
    for (int i=1;i<=n;i++)gn(x[i]),su+=x[i];
    f[0][0]=1.0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=n*m;j++)f[i&1][j]=0.0;
        for (int j=0;j<=n*m;j++){
            ad(f[i&1],j+1,j+x[i]-1,f[(i-1)&1][j]);
            ad(f[i&1],j+x[i]+1,j+m,f[(i-1)&1][j]);
        }
        for (int j=1;j<=n*m;j++)f[i&1][j]+=f[i&1][j-1];
        for (int j=0;j<=n*m;j++)f[i&1][j]/=(m-1);
    }
    db an=0.0;
    for (int j=0;j<su;j++)an+=f[n&1][j];
    an*=(m-1);
    an+=1.0;
    printf("%.15lf\n",an);
    return 0;
}