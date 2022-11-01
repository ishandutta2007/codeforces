#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
void ary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void ary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=2e5+5,mod=1e9+7;
const double eps=1e-8,pi=acos(-1);
struct vec
{
    double x,y;
    vec(double x=0,double y=0):x(x),y(y){}
    vec operator+(const vec&o)const{ return vec(x+o.x,y+o.y);}
    vec operator-(const vec&o)const{ return vec(x-o.x,y-o.y);}
    double operator*(const vec&o)const{ return x*o.x+y*o.y;}
    double operator^(const vec&o)const{ return x*o.y-y*o.x;}
    vec operator/(const double&o)const{ return vec(x/o,y/o);}
    vec operator*(const double&o)const{ return vec(x*o,y*o);}
    void sc(){scanf("%lf%lf",&x,&y);}
    double len(){return sqrt(x*x+y*y);}
};
int n,k;
vec s1,s2,a[N];
vec polar(double a,double r){return vec(cos(r)*a,sin(r)*a);}//ar
bool intersect(vec c1,vec c2,double r1,double r2)//cr
{
    double d=(c1-c2).len();
    if(d-eps>r1+r2||fabs(r1-r2)-d>0) return false;// 
    double a=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
    double t=atan2(c2.y-c1.y,c2.x-c1.x);
    s1=c1+polar(r1,t-a);
    s2=c1+polar(r1,t+a);
    return true;
}
bool judge(double m)
{
  vector<pair<double,double>>vc;
  for(int i=1;i<=n;i++)
  {
    if(intersect({0,0},a[i],m,m))
    {
      double p1=atan2(s1.y,s1.x),p2=atan2(s2.y,s2.x);
      if(p1<0) p1+=2*pi;
      if(p2<0) p2+=2*pi;
      if(p1>p2) swap(p1,p2);
      vec p=polar(m,(p1+p2)/2);
      if((p-a[i]).len()<=m) vc.push_back({p1,p2});
      else vc.push_back({0,p1}),vc.push_back({p2,2*pi});
    }
  }
  sort(vc.begin(),vc.end());
  priority_queue<double,vector<double>,greater<double>>q;
  for(pair<double,double>x:vc)
  {
    while(q.size()&&q.top()<x.first) q.pop();
    q.push(x.second);
    if(q.size()>=k) return true;
  }
  return false;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    scanf("%d%d",&n,&k);
    rep(i,1,n) a[i].sc();
    double l=0,r=2e5;
    rep(i,1,50)
    {
      double m=(l+r)/2;
      if(judge(m)) r=m;
      else l=m;
    }
    printf("%.10f\n",r);
}