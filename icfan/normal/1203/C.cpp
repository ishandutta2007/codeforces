#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 400000
#define Maxm 1000000
#define ll long long
int n;
ll a[Maxn+5];
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int p[Maxm+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll sum=a[1];
	for(int i=2;i<=n;i++){
		sum=gcd(sum,a[i]);
	}
	int len=0;
	for(int i=2;(ll)i*i<=sum;i++){
		if(sum%i==0){
			len++;
			while(sum%i==0){
				sum/=i;
				p[len]++;
			}
		}
	}
	if(sum>1){
		p[++len]=1;
	}
	ll ans=1;
	for(int i=1;i<=len;i++){
		ans*=(p[i]+1);
	}
	cout<<ans<<endl;
	return 0;
}