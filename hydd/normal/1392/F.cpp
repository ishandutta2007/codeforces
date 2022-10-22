#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,h[1100000];
int main(){
	scanf("%d",&n); ll sum=0,h;
	for (int i=0;i<n;i++){
		scanf("%lld",&h); h-=i;
		sum+=h;
	}
	ll c;
	for (int i=0;i<n;i++){
		c=sum/n+(i<sum%n);
		printf("%lld ",c+i);
	}
	return 0;
}