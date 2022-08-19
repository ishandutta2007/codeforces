#include <cstdio>
#include <iostream>
using namespace std;

long long n,T,ans;
long long a[200010];
int main(){
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(;;){
		long long cost=0,tot=0;
		for(int i=1;i<=n;i++){
			if(a[i]+cost<=T){
				cost+=a[i];
				tot++;
			}
		}
		if(tot==0)break;
		ans+=(T/cost)*tot;
		T%=cost;
	}
	cout<<ans;
}