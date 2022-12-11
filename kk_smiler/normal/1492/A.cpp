#include <bits/stdc++.h>
using namespace std;
int n,m,T;
long long a,b,c,p;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		long long ans=LLONG_MAX;
		ans=min(ans,(p/a+(p%a>0))*a);
		ans=min(ans,(p/b+(p%b>0))*b);
		ans=min(ans,(p/c+(p%c>0))*c);
		printf("%lld\n",ans-p);
	}
}