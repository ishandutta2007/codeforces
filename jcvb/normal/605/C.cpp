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
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789
using namespace std;
int n,p,q;

struct pkt{
    int x,y;
}a[111111];
int cmp(const pkt&a,const pkt&b){
    if(a.x==b.x)return a.y>b.y;
    else return a.x<b.x;
}
pkt operator-(const pkt&a,const pkt&b){
    return (pkt){a.x-b.x,a.y-b.y};
}
ll operator*(const pkt&a,const pkt&b){
    return 1ll*a.x*b.y-1ll*a.y*b.x;
}
ll det(ll a,ll b,ll c,ll d){
    return a*d-b*c;
}
pkt s[111111];int top=0;


db ca1(const pkt&a){
    return max(1.0*p/a.x,1.0*q/a.y);
}

db ca2(const pkt&a,const pkt&b){
    ll d=det(a.x,b.x,a.y,b.y);
    ll d1=det(p,b.x,q,b.y);
    ll d2=det(a.x,p,a.y,q);
    return max(0.0,1.0*d1/d)+max(0.0,1.0*d2/d);
}
int main()
{
    gn(n);gn(p);gn(q);
    for (int i=1;i<=n;i++)gn(a[i].x),gn(a[i].y);
    sort(a+1,a+1+n,cmp);

    for (int i=1;i<=n;i++){
        if(i>1 && a[i].x==a[i-1].x)continue;
        while(top>=1 && a[i].y>=s[top].y)top--;
        while(top>=2 && (s[top]-s[top-1])*(a[i]-s[top])>=0)top--;
        s[++top]=a[i];
    }

    db mi=1e18;

    for (int i=1;i<=top;i++)mi=min(mi,ca1(s[i]));
    for (int i=1;i<top;i++)mi=min(mi,ca2(s[i],s[i+1]));
    printf("%.10lf\n",mi);
    return 0;
}