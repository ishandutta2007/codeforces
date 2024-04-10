#include<bits/stdc++.h>
using namespace std;
long long t,a,k;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>k;
		for(long long i=2;i<=k;i++){
			long long b=a;
			long long mi=10,ma=0;
			while(b){
				mi=min(mi,b%10);
				ma=max(ma,b%10);
				b/=10;
			}
			a+=mi*ma;
			if(!mi){
				break;
			}
		}
		cout<<a<<endl;
	}
	return 0;
}