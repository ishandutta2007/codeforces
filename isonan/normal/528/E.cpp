#include <algorithm>
#include <cstdio>
#include <cmath>

struct point{
	double x,y;
	double cross(point a){return x*a.y-y*a.x;}
}P,s;
struct line{
	double a,b,c;
	operator double(){return atan2(b,a);}
	point intersect(line rhs){double temp=rhs.a*b-rhs.b*a;return (point){(rhs.c*b-c*rhs.b)/temp,(c*rhs.a-a*rhs.c)/temp};}
}num[100001];
int n;
double ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&num[i].a,&num[i].b,&num[i].c);
		if(num[i].a<0.)num[i].a*=-1.,num[i].b*=-1.,num[i].c*=-1.;
	}
	std::sort(num+1,num+n+1);
	for(int i=1;i<=n;i++){
		P=(point){0,0};
		for(int j=(i==n)?1:i+1;j!=i;(j==n)?j=1:(++j)){
			s=num[i].intersect(num[j]);
			ans+=P.cross(s);
			P.x+=s.x,P.y+=s.y;
		}
	}
	printf("%.12lf\n",(ans/2.)/(double)((1ll*n*(n-1)*(n-2))/6ll));
}