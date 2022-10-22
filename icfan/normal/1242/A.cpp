#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 1000000
ll n;
ll p[Maxn+5],num[Maxn+5];
int len;
void work(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			p[++len]=i;
			num[len]=0;
			while(n%i==0){
				num[len]++;
				n/=i;
			}
		}
	}
	if(n>1){
		p[++len]=n;
		num[len]=1;
	}
}
int main(){
	cin>>n;
	if(n==1){
		puts("1");
		return 0;
	}
	work(n);
	if(len>1){
		puts("1");
		return 0;
	}
	cout<<p[len]<<endl;
	return 0;
}