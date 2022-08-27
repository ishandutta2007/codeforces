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
int n,m;
char b[555][555];

int v[555][555],h[555][555];


int f(int a[555][555],int r1,int c1,int r2,int c2){
    return a[r2][c2]-a[r1-1][c2]-a[r2][c1-1]+a[r1-1][c1-1];
}
int main()
{
    gn(n);gn(m);
    for (int i=1;i<=n;i++)
        scanf("%s",b[i]+1);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            if(b[i][j]=='.' && b[i][j+1]=='.'){
                h[i][j]=1;
            }
            if(b[i][j]=='.' && b[i+1][j]=='.'){
                v[i][j]=1;
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            v[i][j]+=v[i][j-1];
            h[i][j]+=h[i][j-1];
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            v[i][j]+=v[i-1][j];
            h[i][j]+=h[i-1][j];
        }

    int q;gn(q);
    while(q--){
        int r1,c1,r2,c2;
        gn(r1);gn(c1);gn(r2);gn(c2);
        int ans=f(v,r1,c1,r2-1,c2)+f(h,r1,c1,r2,c2-1);
        printf("%d\n",ans);
    }
    return 0;
}