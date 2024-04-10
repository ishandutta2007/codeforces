#include <cstdio>
#include <vector>
#include <algorithm>
using std::min;

struct point{double a,b;operator double(){return b;}}f[12010];
int top,n;
double X[12010],apex,ans,q,a,b,mn[6010];
int main(){
	scanf("%d%lf%lf%lf",&n,&q,&a,&b);
	for(int i=1;i<=n;i++)scanf("%lf",X+i);
	for(int i=1;i<=n;i++){
		if(i==1)f[1]=(point{1.0,1.0-X[1]}),f[2]=((point){q+1,q+1.-X[1]}),top=2;
		else{
			int p=std::upper_bound(f+1,f+top+1,0.0)-f;
			double tem=p==1?f[1].a:p==top+1?q:((f[p].a-f[p-1].a)/(f[p].b-f[p-1].b))*(-f[p-1].b)+f[p-1].a;
			for(int i=top;i>=p;i--)f[i+2]=f[i];
			f[p]=f[p+1]=(point){tem,0.0},top+=2;
			for(int i=p;i;i--)f[i].a+=a;
			for(int i=p+1;i<=top;i++)f[i].a+=b;
			mn[i-1]=min(tem,q);
			for(int j=1;j<=top;j++)f[j].b+=f[j].a-X[i];
		}
	}
	int p=std::upper_bound(f+1,f+top+1,0.0)-f;
	double tem=p==1?f[1].a:p==top+1?q:((f[p].a-f[p-1].a)/(f[p].b-f[p-1].b))*(-f[p-1].b)+f[p-1].a;
	mn[n]=min(tem,q);
	for(int i=n-1;i;i--)
		if(mn[i]<mn[i+1]-b)mn[i]=mn[i+1]-b;
		else  if(mn[i]>mn[i+1]-a)mn[i]=mn[i+1]-a;
	for(int i=1;i<=n;i++)printf("%.6lf ",mn[i]),ans+=pow(mn[i]-X[i],2);
	printf("\n%.6lf",ans);
}