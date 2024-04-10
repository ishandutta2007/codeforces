#include <cstdio>

int T,n,l,a[100001];
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d%d",&n,&l);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		double L=0.,R=(double)l,t=0.;
		int now1=1,now2=n,v1=1,v2=1;
		for(;;){
//			printf("%d %d %d %d\n",now1,now2,v1,v2);
			double t1=((double)a[now1]-L)/(double)v1;
			double t2=(R-(double)a[now2])/(double)v2;
			if(now1>now2){
				t+=(R-L)/(double)(v1+v2);
				break;
			}
			double fin=(t1<t2)?t1:t2; 
			t+=fin;
			R-=fin*v2;
			L+=fin*v1;
			if(t1<t2)++now1,++v1;
			else --now2,++v2;
		}
		printf("%.6lf\n",t);
	}
}