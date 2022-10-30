#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t;
ll a[400500],res,sb;
int main(){
	scanf("%d",&t);
	while(t--){
		res=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		a[n+1]=0;
		for(i=1;i<=n;i++){
			sb=max(a[i-1],a[i+1]);
			if(sb<=a[i]){
				res+=a[i]-sb;
				a[i]=sb;
			}
		}
		for(i=1;i<=n+1;i++){
			res+=abs(a[i]-a[i-1]);
		}
		printf("%lld\n",res);
	}
}