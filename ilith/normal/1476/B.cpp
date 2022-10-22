#include<bits/stdc++.h>
using namespace std;
long long t,n;
long double k;
long long p[10010],sum[10010];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		long long ans=0;
		sum[0]=p[0]=0;
		for(long long i=1;i<=n;i++){
			cin>>p[i];
			sum[i]=p[i]+sum[i-1];
			if(i!=1)ans=max(ans,(long long)ceil(p[i]*(double)100.0/k)-sum[i-1]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}