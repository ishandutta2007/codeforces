#include <algorithm>
#include <cstdio>
#include <cmath>
#define int long long

double a,b,c,x1,y1,x2,y2;
double ans;
double abs(double x){return x<0.?-x:x;}
double dist(double x1,double y1,double x2,double y2){
	return sqrt(pow(x1-x2,2.)+pow(y1-y2,2.));
}
double check(double x1,double y1,double x2,double y2){
	double ans=1e18;
	double tem=(double)(-x2*a-c)/(double)b;
	double dis=abs(tem-(double)y2);
	ans=std::min(ans,dis+dist(x1,y1,x2,tem));
	tem=(double)(-y2*b-c)/(double)a;
	dis=abs(tem-(double)x2);
	ans=std::min(ans,dis+dist(x1,y1,tem,y2));
	return ans;
}
signed main(){
	scanf("%lf%lf%lf",&a,&b,&c);
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	ans=abs(x1-x2)+abs(y1-y2);
	double tem=(double)(-x1*a-c)/(double)b;
	double dis=abs(tem-(double)y1);
	ans=std::min(ans,check(x1,tem,x2,y2)+dis);
	tem=(double)(-y1*b-c)/(double)a;
	dis=abs(tem-(double)x1);
	ans=std::min(ans,check(tem,y1,x2,y2)+dis);
	printf("%.7lf\n",ans);
}