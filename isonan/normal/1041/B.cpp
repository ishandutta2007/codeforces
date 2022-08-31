#include <cstdio>
#include <iostream>
using namespace std;

long long a,b,x,y;
long long gcd(long long a,long long b){
	if(!b)return a;
	return gcd(b,a%b);
}
long long min(long long a,long long b){
	return a<b?a:b;
}
int main(){
	cin>>a>>b>>x>>y;
	long long tem=gcd(x,y);
	x/=tem;
	y/=tem;
	cout<<min(a/x,b/y);
}