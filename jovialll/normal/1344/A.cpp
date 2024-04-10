#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int t,n,ans,i,a[N],c[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;++i)cin>>a[i];
		for(i=0;i<n;++i)c[i]=0;
		for(i=0;i<n;++i)c[((i+a[i])%n+n)%n]++;
		ans=1;
		for(i=0;i<n;++i)if(!c[i])ans=0;
		if(ans)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}