#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
	int x,y;
	void scan(){
		scanf("%d%d",&x,&y);
	}
}A,B,R,x[110000];
#define sqr(x) (1ll*(x)*(x))
double dis(point k1,point k2){
	return sqrt(sqr(k1.x-k2.x)+sqr(k1.y-k2.y));
}
int n,where;
double now;
double tot;
int main(){
	A.scan(); B.scan(); R.scan();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) x[i].scan();
	tot=0;
	for (int i=1;i<=n;i++) tot+=dis(x[i],R)*2;
	where=0; now=1e18;
	for (int i=1;i<=n;i++)
		if (dis(x[i],A)-dis(x[i],R)<now){
			where=i; now=dis(x[i],A)-dis(x[i],R);
		}
	double ans=1e18;
	for (int i=1;i<=n;i++)
		ans=min(ans,tot+min(dis(x[i],A),dis(x[i],B))-dis(x[i],R));
	if (n!=1)
		for (int i=1;i<=n;i++)
			if (i!=where)
				ans=min(ans,tot+now+dis(x[i],B)-dis(x[i],R));
			else for (int j=1;j<=n;j++)
				if (j!=where)
					ans=min(ans,tot+dis(x[i],B)-dis(x[i],R)+dis(x[j],A)-dis(x[j],R));
	printf("%.11lf\n",ans);
	return 0;
}