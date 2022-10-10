#include<stdio.h>
#include<iostream>
#define int long long
using namespace std;
int a,b;
pair<int,int>ggcd(int a,int b){
	if(a==0||b==0)
		return make_pair(a,b);
	if(a>=b+b)
		return ggcd(a%(b+b),b);
	if(b>=a+a)
		return ggcd(a,b%(a+a));
	return make_pair(a,b);
}
signed main(){
	scanf("%lld%lld",&a,&b);
	pair<int,int>v=ggcd(a,b);
	printf("%lld %lld\n",v.first,v.second);
	return 0;
}