#include<iostream>
#include<algorithm>
using namespace std;
long long  n,k,a,l,b,ans1,ans2=(long long)(1e15+1000);
long long gcd(long long x,long long y){
	if(y==0)return x;
	else{return gcd(y,x%y);}
}
int main(){
	cin>>n>>k>>a>>b;
	long long c[10];
	c[1]=a+b;c[2]=a-b;c[3]=-a-b;c[4]=-a+b;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=4;j++){
			long long l=i*k+c[j];
			long long ans=n*k/gcd(l,n*k);
			ans1=max(ans1,ans);
			ans2=min(ans2,ans);
		}
	}
	cout<<ans2<<' '<<ans1;
	return 0;
}