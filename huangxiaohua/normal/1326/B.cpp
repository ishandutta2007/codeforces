#include<bits/stdc++.h>
using namespace std;

long long n,t,mx,res;

int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		res=n+mx;
		mx=max(mx,res);
		printf("%lld ",res);
	}
}