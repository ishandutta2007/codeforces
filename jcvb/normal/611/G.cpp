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
typedef unsigned long long ull;
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
struct pkt{
    int x,y;
}p[1055555];
ll operator* (const pkt&a,const pkt&b){
    return 1ll*a.x*b.y-1ll*a.y*b.x;
}
pkt operator-(const pkt&a,const pkt&b){
    return (pkt){a.x-b.x,a.y-b.y};
}

ll s(int i,int j,int k){//ni
    return (p[j]-p[i])*(p[k]-p[i]);
}

int sx=0,sy=0,sc=0;int cnt=0;
int cx=0,cy=0,cc=0;
//int cnt=0;
inline void upd(int &a,int b){
    a=(a+b)%mo;
}
void lmv(int i){
    int dc=p[i]*p[i+1]%mo,dx=(p[i].y-p[i+1].y)%mo,dy=(p[i+1].x-p[i].x)%mo;
    upd(sx,-1ll*dx*cnt%mo);
    upd(sy,-1ll*dy*cnt%mo);
    upd(sc,-1ll*dc*cnt%mo);
    upd(cx,-dx);
    upd(cy,-dy);
    upd(cc,-dc);
    cnt--;
}
void rmv(int i){
    int dc=p[i]*p[i+1]%mo,dx=(p[i].y-p[i+1].y)%mo,dy=(p[i+1].x-p[i].x)%mo;
    cnt++;
    upd(cx,dx);
    upd(cy,dy);
    upd(cc,dc);
    upd(sx,cx);
    upd(sy,cy);
    upd(sc,cc);
}
int main()
{
    gn(n);
    for (int i=n;i>=1;i--)gn(p[i].x),gn(p[i].y);
    for (int i=n+1;i<=2*n;i++)p[i]=p[i-n];

    ull tots=0;
    for (int i=1;i<=n;i++)tots+=p[i]*p[i+1];
    ull curs=0;
    int ans=0;
    for (int i=1,j=1;i<=n;lmv(i),curs-=s(i,i+1,j),i++){
        while(1){
            ll del=s(i,j,j+1);
            if((curs+del)>tots/2)break;
            rmv(j);
            j++;
            curs+=del;
        }
        int rigsum=(1ll*sx*p[i].x+1ll*sy*p[i].y+sc)%mo;
        int nu=j-i-1;
        int del=(1ll*(tots%mo)*nu-2ll*rigsum)%mo;
        ans=(ans+del)%mo;
    }
    printf("%d\n",(ans+mo)%mo);
    return 0;
}