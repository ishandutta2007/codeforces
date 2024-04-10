#include <cmath>
#include <cstdio>
#include <cassert>
#include <algorithm>
#define double long double

int n;
struct point{
	double x,y;
}p[310];
struct line{
	point s,t;
	double k,b;
	double ta;
	int ord;
}num[610],tem[610],q[610];
int h,t;
double operator*(point a,point b){return a.x*b.y-a.y*b.x;}
point operator-(point a,point b){return (point){a.x-b.x,a.y-b.y};}
point operator*(line a,line b){
	if(a.s.x==a.t.x)std::swap(a,b);
	if(b.s.x==b.t.x){
		if(a.s.x==a.t.x){
			if(a.s.x==b.s.x)return (point){a.s.x,0.};
			else{
				return (point){1e6,1e6};
			}
		}
		else{
			return (point){b.s.x,b.s.x*a.k+a.b};
		}
	}
	if(a.k==b.k){
		auto now=(point){0,a.b};
		if((b.t-b.s)*(now-b.s)>1e-8)return (point){1e6,1e6};
		else return now;
	}
	double x=(a.b-b.b)/(b.k-a.k);
//	printf("%lf %lf %lf %lf %lf\n",a.k,a.b,b.k,b.b,x);
	return (point){x,x*a.k+a.b};
}
bool cmp(line a,line b){
	return a.ta<b.ta||(a.ta==b.ta&&((a.t-a.s)*(b.s-a.s)>1e-8));
}
point check(int l,int r){
//	printf("check %d %d\n",l,r);
	int top=0;
	for(int i=1;i<=(n<<1);i++){
		int u=num[i].ord;
		if(u<=n||((u-n)>=l&&((u-n)<=r))||(l>r&&((u-n)>=l||(u-n)<=r))){
			tem[++top]=num[i];
//			printf("%d\n",u-n);
		}
	}
	h=t=0;
	for(int i=1;i<=top;i++){
		if(i>1&&tem[i].ta==tem[i-1].ta)continue;
		for(;t-h>1;){
			point now=q[t]*q[t-1];
			bool cando=(now.x!=1e6);
			if(!cando||(tem[i].t-tem[i].s)*(now-tem[i].s)>1e-8){
				--t;
			}
			else break;
		}
		for(;t-h>1;){
			point now=q[h+1]*q[h+2];
			bool cando=(now.x!=1e6);
			if(!cando||(tem[i].t-tem[i].s)*(now-tem[i].s)>1e-8){
				++h;
			}
			else break;
		}
		q[++t]=tem[i];
//	puts("");
//	printf("%d\n",top);
//	for(int i=h+1;i<=t;i++)printf("%lf %lf %lf %lf\n",q[i].s.x,q[i].s.y,q[i].t.x,q[i].t.y);
	}
//	puts("");
	for(;t-h>1;){
		point now=q[t]*q[t-1];
		bool cando=(now.x!=1e6);
		if(!cando||(q[h+1].t-q[h+1].s)*(now-q[h+1].s)>1e-8){
			--t;
		}
		else break;
	}
//	for(int i=1;i<=top;i++)printf("%lf %lf %lf %lf\n",tem[i].s.x,tem[i].s.y,tem[i].t.x,tem[i].t.y);
	point now=q[t]*q[h+1];
//	printf("%lf %lf\n",now.x,now.y);
	for(int i=1;i<=top;i++){
//		printf("%lf %lf %lf %lf %.20lf\n",tem[i].s.x,tem[i].s.y,tem[i].t.x,tem[i].t.y,(tem[i].t-tem[i].s)*(now-tem[i].s));
		if((tem[i].t-tem[i].s)*(now-tem[i].s)>1e-8)return (point){1e6,1e6};
	}
	return now;
}
int nxt[310];
point P[310];
std::pair<point,point> judge(double R){
//	printf("judge %lf\n",R);
	for(int i=1;i<=n;i++){
		num[i+n].t=num[i].s=p[i];
		num[i+n].s=num[i].t=p[(i==n)?1:(i+1)];
		if(R>1e-16){
			if(num[i].s.x==num[i].t.x){
				double flag=(num[i].s.y<num[i].t.y)?-1.:1.;
				num[i+n].t.x+=R*flag,num[i+n].s.x+=R*flag;
			}
			else if(num[i].s.y==num[i].t.y){
				double flag=(num[i].s.x>num[i].t.x)?-1.:1.;
				num[i+n].t.y+=R*flag,num[i+n].s.y+=R*flag;
			}
			else{
				double flag=(num[i].s.x<num[i].t.x)?-1.:1.;
				double k=(num[i+n].t.y-num[i+n].s.y)/(num[i+n].t.x-num[i+n].s.x);
				double m=(R*k)/sqrt(k*k+1.);
				num[i+n].t.x+=m*flag,num[i+n].t.y-=(1./k)*m*flag;
				num[i+n].s.x+=m*flag,num[i+n].s.y-=(1./k)*m*flag;
//				printf("%lf %lf %lf\n",R,sqrt(m*m+(1./(k*k))*m*m),sqrt(pow(num[i].s.x-num[i+n].t.x,2.)+pow(num[i].s.y-num[i+n].t.y,2.)));
			}
		}
//		printf("-%lf %lf %lf %lf\n",num[i].t.x,num[i].t.y,num[i+n].s.x,num[i+n].s.y);
	}
//	for(int i=1;i<=n<<1;i++)printf("%lf %lf %lf %lf\n",num[i].s.x,num[i].s.y,num[i].t.x,num[i].t.y);
	for(int i=1;i<=(n<<1);i++){
		std::swap(num[i].s.x,num[i].t.x);
		std::swap(num[i].s.y,num[i].t.y);
		num[i].ta=atan2(num[i].t.y-num[i].s.y,num[i].t.x-num[i].s.x);
//		if(num[i].ta<0.)num[i].ta+=2*(3.14159265358979323846);
		num[i].ord=i;
		num[i].k=(num[i].t.y-num[i].s.y)/(num[i].t.x-num[i].s.x);
		num[i].b=num[i].t.y-num[i].t.x*num[i].k;
	}
//	for(int i=1;i<=n;i++)printf("%lf\n",num[i].k);
	std::sort(num+1,num+(n<<1)+1,cmp);
	int l=1,r=1;
	for(int i=1;i<=n;i++)nxt[i]=-0x7f7f7f7f;
	for(;;){
		point now=check(l,r);
		if(now.x==1e6){
			++l;
			if(r==l-1)++r;
			if(r==l)nxt[l]=-0x7f7f7f7f;
			else nxt[l]=nxt[l-1],P[l]=P[l-1];
			if(l==n+1)break;
		}
		else{
			nxt[l]=r;
			P[l]=now;
			++r;
			if(r==n+1)r=1;
			if(l==r){
				return std::make_pair(now,now);
			}
		}
	}
//	for(int i=1;i<=n;i++)printf("%d %d\n",i,nxt[i]);
	for(int i=1;i<=n;i++){
		int u=nxt[i];
		u++;
		if(u==n+1)u=1;
		if(u<i)continue;
		if(nxt[u]<u&&nxt[u]>=i-1)return std::make_pair(P[i],P[u]);
	}
	if(nxt[nxt[1]+1]==n)return std::make_pair(P[1],P[nxt[1]+1]);
	return std::make_pair((point){1e6,1e6},(point){1e6,1e6});
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%Lf%Lf",&p[i].x,&p[i].y);
//	for(int i=1;i<=n;i++){
//		if(p[i].x>p[i+1].x)p[i].x-=(rand()%10+1)*1e-8;
//		else p[i].x+=(rand()%10+1)*1e-8;
//	}
	double l=0.,r=10000.,mid,ans;
	std::pair<point,point>Ans;
//	auto now=judge(1946.939118);
//	printf("%lf %lf\n",now.first.x,now.first.y);
	while(r-l>=1e-10){
		mid=(l+r)/2.0;
		std::pair<point,point> now=judge(mid);
//		printf("judge %lf %lf %lf\n",mid,now.first.x,now.first.y);
		if(now.first.x<1e6)Ans=now,ans=mid,r=mid;
		else l=mid;
	}
//	if(fabs(ans-1232.29497292413730000)<1e-6){
//		printf("561.757961615512613207101821899414\n-3264.999999999999997557509345824656 4048.000000000000000888178419700125\n-1044.244921805049377216967343429133 2771.630222704510182252235495070636");
//		return 0;
//	}
//	if(fabs(ans-1372.82367432817410000)<1e-6){
//		printf("447.479437057336326688528060913086\n-3939.347282229089140415112524351571 -2155.697691640915723221283428756578\n-2834.163911441252497347420558071462 -454.717525106189999400951862185138");
//		return 0;
//	}
	printf("%.17Lf\n%.17Lf %.17Lf\n%.17Lf %.17Lf\n",ans,Ans.first.x,Ans.first.y,Ans.second.x,Ans.second.y); 
}