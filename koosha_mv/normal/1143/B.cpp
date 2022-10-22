#include<iostream>
using namespace std;long long p=1;
long long siz(long long n){
	long long p=1;
	while(n>9){
		n/=10;
		p++;
	}
	return p;
}
long long f(long long n,long long x){
	while(x--)
		n/=10;
	return n%10;
}
long long menha(long long n,long long x){
	if(x==siz(n)-1){
		if(f(n,x)>1){
			p*=f(n,x)-1;
		}
		return 0;
		}
	if(f(n,x)>0){
		p*=f(n,x)-1;
		for(long long i=x+1;i<siz(n);i++){
			p*=f(n,i);
		}
	}
	else
	{
		p*=9;
		menha(n,x+1);
	}
	return 0;
}
long long n,mx=0;
int main(){
	cin>>n;
	p=1;
	for(int i=0;i<siz(n);i++){
		p*=f(n,i);
	}
	mx=p;
	for(long long i=0;i<siz(n);i++){
		p=1;
		for(long long j=0;j<i;j++){
			p*=9;
		}
		menha(n,i);
		mx=max(mx,p);
	}
	cout<<mx;
}