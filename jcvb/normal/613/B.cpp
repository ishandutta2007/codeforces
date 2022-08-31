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

int n,A,cf,cm;
ll m;
struct node{
    int a,id;
}a[111111];
int cmp(const node&a,const node&b){
    return a.a<b.a;
}
int cmp2(const node&a,const node&b){
    return a.id<b.id;
}
int aa[111111];
ll ned[111111];
ll su[111111];


int check(int mid,int cnt,ll can){
    cnt=upper_bound(aa+1,aa+1+cnt,mid)-aa-1;
    ll ned=1ll*cnt*mid-su[cnt];
    return ned<=can;
}
ll calc(int cnt,ll can){
    int lef=0,rig=A,mid;
    while(lef<=rig){
        mid=lef+rig>>1;
        if(check(mid,cnt,can))lef=mid+1;
        else rig=mid-1;
    }
    return rig;
}
int main()
{
    gn(n);gn(A);gn(cf);gn(cm);gn(m);
    for (int i=1;i<=n;i++)gn(a[i].a),a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++)aa[i]=a[i].a;
    ned[0]=0;
    for (int i=1;i<=n;i++)ned[i]=ned[i-1]+A-a[n-i+1].a;
    su[0]=0;
    for (int i=1;i<=n;i++)su[i]=su[i-1]+a[i].a;
    ll ma=0;int opt;ll tmpok;
    for (int i=0;i<=n;i++)if(ned[i]<=m){
        ll can=m-ned[i];
        ll ok=calc(n-i,can);
        ll tmp=cm*ok+cf*i;
        if(tmp>=ma){
            ma=tmp;
            opt=i;
            tmpok=ok;
        }
    }
    printf("%I64d\n",ma);
    for (int i=n;i>=n-opt+1;i--)a[i].a=A;
    for (int i=1;i<=n;i++)if(a[i].a<tmpok)a[i].a=tmpok;
    sort(a+1,a+1+n,cmp2);

    for (int i=1;i<=n;i++)printf("%d ",a[i].a);
    printf("\n");
    return 0;
}