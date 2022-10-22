#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#define LL long long
#define N 1050 
using namespace std;
int n,a,b,m,s=0,ans=0;
int d[N],c[N],l[1000050],r[1000050];
struct date{
	int x,id;
}e[N];
bool cmp(date x,date y){
	return x.x<y.x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&d[i]);
	a=d[n+1>>1];m=d[n]+1;
	for(int i=1;i<=m;++i) c[i]=a;
	for(int i=1;i<=n;++i) c[i]=d[i];
	for(int i=1;i<=m;++i) s+=c[i];
	if(s&1){
		b=1e9;
		for(int i=1;i<=n;++i)
			if((d[i]&1)!=(a&1)&&abs(d[i]-a)<abs(b-a)) b=d[i];
		c[m]=b;
	}
	for(int i=1;i<=m;++i)
		e[i].x=c[i],e[i].id=i;
	sort(e+1,e+1+m,cmp);
	while(e[m].x){
		for(int i=m-1;i>=1&&e[m].x;--i){
			++ans;l[ans]=e[i].id;r[ans]=e[m].id;
			--e[m].x;--e[i].x;
		}
		sort(e+1,e+1+m,cmp);
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)
		printf("%d %d\n",l[i],r[i]);
	return 0;
}