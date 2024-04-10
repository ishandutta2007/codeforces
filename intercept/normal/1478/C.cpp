#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+9;
int n;
ll a[M],sum,la;
void work(){
	sum=0;
	scanf("%d",&n);
	la=1ll<<60;
	for(int i=1;i<=n*2;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n*2+1);
	for(int i=n*2;i>=1;i-=2){
		if(a[i]!=a[i-1]){
			printf("NO\n");
			return;
		}
		ll x=(a[i]-sum);
		if(x%i!=0||x<=0||x/i>=la){
			printf("NO\n");
			return;
		}
		sum+=2ll*x/i;
		la=x/i;
	}
	printf("YES\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}