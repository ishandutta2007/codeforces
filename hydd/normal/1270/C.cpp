#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); int v;
		ll s=0,x=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&v);
			s+=v; x^=v;
		}
		printf("2\n%lld %lld\n",x,s+x);
	}
	return 0;
}