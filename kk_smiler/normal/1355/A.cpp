#include <bits/stdc++.h>
using namespace std;
int T,n,m,p;
long long a,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld",&a,&k),k--;
		while(k--){
			long long cy=a,mx=0,mn=10;
			while(cy) mx=max(cy%10,mx),mn=min(cy%10,mn),cy/=10;
			if(mn==0) break;
			a+=mx*mn;
		}
		printf("%lld\n",a);
	}
}