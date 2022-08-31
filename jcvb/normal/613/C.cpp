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
int a[333];
int n;
void out(int i,int t){
    for (int j=0;j<t;j++)putchar(i-1+'a');
}
int ord[333];
int main()
{
    gn(n);
    for (int i=1;i<=n;i++)gn(a[i]);
    int su=0;
    int numodd=0;
    for (int i=1;i<=n;i++)numodd+=a[i]&1,su+=a[i];
    if(numodd>1){
        printf("0\n");
        for (int i=1;i<=n;i++)out(i,a[i]);
        putchar('\n');
        return 0;
    }
    int d=0;
    for (int i=1;i<=n;i++)d=gcd(d,a[i]);
    int no1=0;
    for (int i=1;i<=n;i++)no1+=(a[i]/d)&1;
    if(no1>1 && d%2==0)d/=2,no1=0;
    for (int i=1;i<=n;i++)a[i]/=d;
    for (int i=1;i<=n;i++)ord[i]=i;
    for (int i=1;i<=n;i++)if(a[i]&1)swap(ord[i],ord[n]);
    if(no1){
        printf("%d\n",d);
    }else printf("%d\n",d*2);
    for (int tt=1;tt<=d;tt++){
        for (int i=1;i<=n-1;i++){
            out(ord[i],a[ord[i]]/2);
        }
        out(ord[n],a[ord[n]]);
        for (int i=n-1;i>=1;i--){
            out(ord[i],a[ord[i]]/2);
        }
    }
    return 0;
}