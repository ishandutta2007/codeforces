#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	int t;
	int n,g,b;
	scanf("%d",&t);
	ll num;
	ll now,ans,tmp;
	while(t--){
		scanf("%d%d%d",&n,&g,&b);
		num=(n+1)>>1;
		ans=0;
		now=(num-1)/g;
		tmp=num-now*g;
		ans=now*(g+b)+tmp;
		if(ans<n){
			printf("%d\n",n);
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}