#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}
#define double long double

double sx,sy,tx,ty;
double a,b,c;

inline double Dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	cin>>a>>b>>c;
	cin>>sx>>sy>>tx>>ty;

	if(sx==tx)printf("%.10Lf\n",fabs(ty-sy)),exit(0);
	if(sy==ty)printf("%.10Lf\n",fabs(tx-sx)),exit(0);
	if(!a || !b)printf("%.10Lf\n",fabs(tx-sx)+fabs(ty-sy)),exit(0);

	double K=-(double)a/b,B=-(double)c/b,dx=sqrt(1+K*K);
	
	double s1=fabs(tx-sx)+fabs(ty-sy);
	double x1,y1,x2,y2,x3,y3,x4,y4;
	double d1,d2,d3,d4;
	x1=sx; y1=x1*K+B; d1=Dis(sx,sy,x1,y1);
	y2=sy; x2=(y2-B)/K; d2=Dis(sx,sy,x2,y2);
	x3=tx; y3=x3*K+B; d3=Dis(tx,ty,x3,y3);
	y4=ty; x4=(y4-B)/K; d4=Dis(tx,ty,x4,y4);
	double ans=1e100;
	chkmin(ans,d1+d3+Dis(x1,y1,x3,y3));
	chkmin(ans,d1+d4+Dis(x1,y1,x4,y4));
	chkmin(ans,d2+d3+Dis(x2,y2,x3,y3));
	chkmin(ans,d2+d4+Dis(x2,y2,x4,y4));
	chkmin(ans,s1);
	printf("%.10Lf\n",ans);
	return 0;
}