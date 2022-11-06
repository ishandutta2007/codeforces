#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)

typedef long long ll;
template<typename T,typename U>inline bool smin(T&x,const U&y){return x>y?x=y,1:0;}
template<typename T,typename U>inline bool smax(T&x,const U&y){return x<y?x=y,1:0;}
const int N=2005;
int n,a,b,na,nb;
double p[N],q[N],ca,cb,nw;
const double eps=1e-10;
void calc(){
	na=nb=0;nw=0;
	REP(i,1,n){
		const double pr=nw;
		const int pa=na,pb=nb;
		if(pr+p[i]-ca-eps>nw)nw=pr+p[i]-ca,na=pa+1;
		if(pr+q[i]-cb-eps>nw)nw=pr+q[i]-cb,nb=pb+1,na=pa;
		if(pr+p[i]-ca+q[i]-cb-p[i]*q[i]-eps>nw)
		nw=pr+p[i]-ca+q[i]-cb-p[i]*q[i],na=pa+1,nb=pb+1;
	}
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	REP(i,1,n)scanf("%lf",&p[i]);
	REP(i,1,n)scanf("%lf",&q[i]);
	double l=0,r=1,L,R;
	REP(k,1,50){
		ca=(l+r)*0.5;
		L=0,R=1;
		REP(t,1,50){
			cb=(L+R)*0.5;
			calc();
			nb>b?L=cb:R=cb;
		}
		na>a?l=ca:r=ca;
	}
	calc();
	printf("%lf\n",nw+ca*a+cb*b);
	return 0;
}