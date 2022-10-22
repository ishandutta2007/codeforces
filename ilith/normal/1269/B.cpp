#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2001],b[2001];
long long ans=1e9+10;
int main(){
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		a[i]%=m;
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		cin>>b[i];
		b[i]%=m;
	}
	sort(b,b+n);
	for(long long i=0;i<n;i++){
		bool fl=1;
		for(long long j=0;j<n;j++){
			if((a[j]+b[i]-a[0]+m)%m!=b[(j+i)%n]){
				fl=0;
			}
		}
		if(fl){
			ans=min(ans,(b[i]-a[0]+m)%m);
		}
	}
	cout<<ans;
	return 0;
}