#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+10;
const double eps=1e-6;
int n,A,B;
int ua,ub;
double ans; 
double a[N],b[N];
void check(double ca,double cb){
	ans=0;ua=0;ub=0;
	double now,na,nb;
	for(int i=1;i<=n;++i){
		na=0;nb=0;now=0;
		if(a[i]-ca>now){
			now=a[i]-ca;
			na=1;nb=0;
		}
		if(b[i]-cb>now){
			now=b[i]-cb;
			na=0;nb=1;
		}
		if(a[i]+b[i]-a[i]*b[i]-ca-cb>now){
			now=a[i]+b[i]-a[i]*b[i]-ca-cb;
			na=1;nb=1;
		}
		ans+=now;
		ua+=na;
		ub+=nb;
	}
	return;
}
void MAIN(){
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;++i){
		scanf("%lf",&a[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%lf",&b[i]);
	}
	double L1=0,R1=1,M1;
	double L2=0,R2=1,M2;
	while(R1-L1>eps){
		M1=(L1+R1)/2;
		L2=0;R2=1;
		while(R2-L2>eps){
			M2=(L2+R2)/2;
			check(M1,M2);
			if(ub>B) L2=M2;
			else R2=M2;
		}
		check(M1,R2);
		if(ua>A) L1=M1;
		else R1=M1;
	}
	check(R1,R2);
//	cout<<ua<<" "<<ub<<" "<<A<<" "<<B<<endl;
	ans+=L1*A+L2*B;
	printf("%0.6lf\n",ans);
	return;
}
int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}