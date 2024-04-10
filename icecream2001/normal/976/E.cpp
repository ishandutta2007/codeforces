#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#define LL long long
#define N 300050 
using namespace std;
int n,a,b,c,d;
LL bin[30],ans=0,ans2=0,re=0;
struct date{
	LL h,d;
}e[N];
bool cmp(date x,date y){
	return (x.h+y.d)>(y.h+x.d);
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	c=min(b-1,n);b=min(b,n);
	bin[0]=1;
	for(int i=1;i<=a;++i) bin[i]=bin[i-1]<<1;
	for(int i=1;i<=n;++i)
		scanf("%I64d%I64d",&e[i].h,&e[i].d);
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;++i)
		if(i<=b&&e[i].h>e[i].d) ans+=e[i].h;
		else ans+=e[i].d;
	for(int i=1;i<=n;++i)
		if(i<=c&&e[i].h>e[i].d) ans2+=e[i].h;
		else ans2+=e[i].d;
	re=ans;
	for(int i=1;i<=n;++i){
		if(i<=b&&e[i].h>e[i].d) 
			re=max(re,ans-e[i].h+e[i].h*bin[a]);
		else if(i<=b)
			re=max(re,ans-e[i].d+e[i].h*bin[a]);
		else if(b) re=max(re,ans2-e[i].d+bin[a]*e[i].h);
	}
	cout<<re<<endl;
	return 0;
}