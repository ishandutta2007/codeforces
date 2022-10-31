#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,t;
ll a,b,c,d,res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		res=0;
		res=max(res,min(a,b)*min(c,d));
		res=max(res,min(a,c)*min(b,d));
		res=max(res,min(a,d)*min(b,c));
		printf("%lld\n",res);
	}
}