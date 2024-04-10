#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#define ld long double
#define ll long long
using namespace std;

int n,m,x[100001],y[100001];
long long d[100001],tem[100001];
std::set<std::pair<long long,long long > >Set;
ld sq(ld x){return x*x;}
void get(ll x,ll y,ll now){
//	if(did.count(std::make_pair(x,y)))return;
//	did.insert(std::make_pair(x,y));
	if(1ll*(x-::x[1])*(x-::x[1])+1ll*(y-::y[1])*(y-::y[1])!=now)return;
//	printf("get %lld %lld %lld\n",x,y,now);
	for(int i=1;i<=n;i++){
		tem[i]=1ll*(x-::x[i])*(x-::x[i])+1ll*(y-::y[i])*(y-::y[i]);
	}
	std::sort(tem+1,tem+n+1);
	for(int i=1;i<=n;i++)if(tem[i]!=d[i])return;
	Set.insert(std::make_pair(x,y));
}
void calc(ll x,ll y,ll now){
//	printf("get %lld %lld\n",x,y);
	for(int i=x-20;i<=x+20;i++)
		for(int j=y-20;j<=y+20;j++)
			get(i,j,now);
}
void check(ll x1,ll y1,ld r1,ll x2,ll y2,ll r2){
	ld dis=sq((ld)x2-((ld)x1/(ld)n))+sq((ld)y2-((ld)y1/(ld)n));
//	printf("%Lf %Lf\n",dis,sqrt(dis));
	if(dis>sq(sqrt(r1)+sqrt((ld)r2))+1e-6)return;
	ld k=std::atan2(((ld)y1/(ld)n-(ld)y2),((ld)x1/(ld)n)-(ld)x2);
	ld p=((ld)((ld)r2+dis-r1))/2./sqrt(dis)/sqrt((ld)r2);
//	printf("%.20Lf %.20Lf\n",p,(ld)r2-r1);
	if(p<-1.)p=-1.;
	if(p>1.)p=1.;
	p=acos(p);
	ld X,Y;
	X=sqrt((ld)r2)*cos(k+p);
	Y=sqrt((ld)r2)*sin(k+p);
	calc(x2+(ll)X,y2+(ll)Y,r2);
	X=sqrt((ld)r2)*cos(k-p);
	Y=sqrt((ld)r2)*sin(k-p);
//	printf("%Lf %Lf\n",(ld)x2+X,(ld)y2+Y);
	calc(x2+(ll)X,y2+(ll)Y,r2);
}
int main(){
	scanf("%d",&n);
	ll sx=0,sy=0;
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i),sx+=x[i],sy+=y[i];
	for(int i=1;i<=n;i++)
		if(1ll*x[i]*n!=sx||1ll*y[i]*n!=sy){
			std::swap(x[1],x[i]);
			std::swap(y[1],y[i]);
			break;
		}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		for(int i=1;i<=n;i++)scanf("%lld",d+i);
//		if(i==28897)printf("%lld %lld %lld\n",d[1],d[2],d[3]);
		std::sort(d+1,d+n+1);
		ld r=0.;
		for(int i=1;i<=n;i++)r+=(ld)d[i]-(sq((ld)x[i]-(ld)sx/(ld)n)+sq((ld)y[i]-(ld)sy/(ld)n));
		r/=n;
//		printf("%Lf\n",r);
		Set.clear();
		for(int i=1;i<=n;i++){
			if(!d[i])calc(x[1],y[1],0);
			else check(sx,sy,r,x[1],y[1],d[i]);
		}
//		if(m<=10){
			printf("%d ",Set.size());
			for(auto it=Set.begin();it!=Set.end();++it)
				printf("%lld %lld ",it->first,it->second);
			putchar('\n');
//		}
	}
}
//3
//8 9
//2 2
//10 4
//1
//9352161115714925 9352161910824178 9352162767110050