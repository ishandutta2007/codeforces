#include<iostream>
#include<cstdio>
using namespace std;
long long k,n;
void solve(){
	scanf("%lld%lld",&k,&n);k--;
	printf("%lld\n",n+k*9);
}
int main(){
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i)solve();
	return 0;
}