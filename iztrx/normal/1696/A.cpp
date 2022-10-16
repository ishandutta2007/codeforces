#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
int T,n,i,j,ans,z;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>z;ans=0;
		for(i=1;i<=n;++i)cin>>j,ans=max(ans,j|z);
		cout<<ans<<"\n";
	}
}