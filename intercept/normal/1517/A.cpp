#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
void work(){
	scanf("%lld",&n);
	if(n%2050){
		printf("-1\n");
		return;
	}
	n/=2050;
	int ans=0; 
	while(n){
		ans+=n%10;
		n/=10;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}