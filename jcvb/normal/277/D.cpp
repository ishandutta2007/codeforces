#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
#define eps 1e-8
#include<cmath>
using namespace std;
typedef long double db;
int n,t;
struct task{	
	int ssc,lsc,st,lt;db p;
}a[1005];
int cmp(const task&a,const task&b){
	return a.p*a.lt*(1-b.p)<b.p*b.lt*(1-a.p);
}
struct data{
	db sc,t;
	data small(db sci,db ti){
		return (data){sc+sci,t+ti};
	}
	data large(db ssc,db lsc,db st,db lt,db p,int T){
		return (data){sc+ssc+(1-p)*lsc,st+p*t+(1-p)*(T+lt)};
	}
};
data max(const data&a,const data&b){
	if(fabs(a.sc-b.sc)<eps)return (data){a.sc,min(a.t,b.t)};
	else if(a.sc>b.sc)return a;
	else return b;
}
data f[2000];
int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i++){
		double tmp;
		scanf("%d%d%d%d%lf",&a[i].ssc,&a[i].lsc,&a[i].st,&a[i].lt,&tmp);a[i].p=tmp;
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		for (int j=t;j>=0;j--){
			if(j>=a[i].st)f[j]=max(f[j],f[j-a[i].st].small(a[i].ssc,a[i].st));
			if(j>=a[i].st+a[i].lt)f[j]=max(f[j],f[j-a[i].st-a[i].lt].large(a[i].ssc,a[i].lsc,a[i].st,a[i].lt,a[i].p,j-a[i].lt-a[i].st));
		}
	}
	data as=(data){0,0};
	for (int j=t;j>=0;j--)as=max(as,f[j]);
	printf("%.15lf %.15lf\n",(double)as.sc,(double)as.t);
	return 0;
}