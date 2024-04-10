#include<bits/stdc++.h>
using namespace std;
int T,n,k,tot,i,a[1000005];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<=n;++i){
			cin>>a[i];
		}
		if(k==1){
			cout<<(n+1>>1)-1<<"\n";
			continue;
		}
		tot=0;
		for(i=2;i<n;++i){
			if(a[i]>a[i-1]+a[i+1])++tot;
		}
		cout<<tot<<"\n";
	}
}