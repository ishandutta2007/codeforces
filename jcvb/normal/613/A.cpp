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
struct pkt{
    int x,y;
    void rd(){
        gn(x);gn(y);
    }
}p[111111],a;
pkt operator-(const pkt&a,const pkt&b){
    return (pkt){a.x-b.x,a.y-b.y};
}
ll sqr(ll x){
    return x*x;
}
ll dis(const pkt&a,const pkt&b){
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
ll pro(const pkt&a,const pkt&b){
    return 1ll*a.x*b.y-1ll*a.y*b.x;
}
int n;

int main()
{
    gn(n);
    a.rd();
    for (int i=1;i<=n;i++)p[i].rd();
    p[0]=p[n];
    double ma=0,mi=1e18;
    for (int i=1;i<=n;i++){
        db di=sqrt(dis(a,p[i]));
        ma=max(ma,di);
        mi=min(mi,di);
    }
    for (int i=0;i<n;i++){
        ll xx=dis(p[i],p[i+1]);
        ll yy=dis(a,p[i]);
        ll zz=dis(a,p[i+1]);
        if(xx+yy>=zz && xx+zz>=yy){
            db di=1.0*abs(pro(p[i]-a,p[i+1]-a))/sqrt(dis(p[i],p[i+1]));
            mi=min(mi,di);
        }
    }
    printf("%.15lf\n",pi*(ma*ma-mi*mi));
    return 0;
}