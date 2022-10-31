#include<bits/stdc++.h>
using namespace std;
 
long long gcd(int a,int b){
	if(b==0){return a;}
	return gcd(b,a%b);
}
 
long long res,tmp,i,j,t,m,d,w,k,n,l,kk;
 
int main(){
	scanf("%lld\n",&t);
	while(t--){
		res=0;
		scanf("%lld%lld%lld",&m,&d,&w);
		k=d-1;
		n=min(m,d);
		l=w/gcd(k,w);
		kk=n/l+1;
		res=(n%l)*(kk-1)*kk/2+(l-n%l)*(kk-1)*(kk-2)/2;
		printf("%lld\n",res);
	}
}