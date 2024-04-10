#include<bits/stdc++.h>

using namespace std;

const int maxn=100010;
int x[maxn],y[maxn],n,m,a,b,xx,yy;
long long ans;

int main(){
	scanf("%d%d",&n,&m);
	xx=yy=n;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(!x[a]){
			x[a]=1;xx--;
		}
		if(!y[b]){
			y[b]=1;yy--;
		}
		ans=(long long)xx*yy;
		printf("%lld ",ans);
	}
	return 0;
}