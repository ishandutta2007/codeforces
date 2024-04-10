//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#define N 400009
using namespace std;
#define ll long long
struct point{
	int x,y;
}a[N];
struct line{
	point a,b;
}b[N];
inline ll dist(point x,point y){
	return 1ll*abs(x.x-y.x)+1ll*abs(x.y-y.y);
}

int main(){
	for(int i=1;i<=3;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	ll ans=1e18;
	point pp;
	for(int i=1;i<=3;++i)
	    for(int j=1;j<=3;++j){
	    	point now=point{a[i].x,a[j].y};
	    	ll dd=0;
	    	for(int k=1;k<=3;++k)
	    	    dd+=dist(a[k],now);
	    	if(dd<ans){
	    		ans=dd;
	    		pp=now;
	    	}
	    }
	int top=0;
	for(int i=1;i<=3;++i){
		if(pp.x==a[i].x&&pp.y==a[i].y)continue;
		if(pp.x!=a[i].x&&pp.y==a[i].y){
			++top;
			b[top].a=point{pp.x,pp.y};
			b[top].b=point{a[i].x,pp.y};
		}
		if(pp.x==a[i].x&&pp.y!=a[i].y){
			++top;
			b[top].a=point{pp.x,pp.y};
			b[top].b=point{pp.x,a[i].y};
		}
		if(pp.x!=a[i].x&&pp.y!=a[i].y){
			++top;
			b[top].a=point{pp.x,pp.y};
			b[top].b=point{a[i].x,pp.y};
			++top;
			b[top].a=point{a[i].x,a[i].y};
			b[top].b=point{a[i].x,pp.y};
		}
	}
	printf("%d\n",top);
	for(int i=1;i<=top;++i){
		printf("%d %d %d %d\n",b[i].a.x,b[i].a.y,b[i].b.x,b[i].b.y);
	}
	return 0;
}