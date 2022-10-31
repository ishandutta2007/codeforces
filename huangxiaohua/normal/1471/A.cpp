#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m;
ll a,b;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		a=b=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			a+=k;
			b+=(ll)ceil(k*1.0/m);
		}
		printf("%lld %lld\n",(ll)ceil(1.0*a/m),b);
	}
}