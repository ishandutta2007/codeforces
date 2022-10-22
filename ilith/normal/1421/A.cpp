#include<bits/stdc++.h>
using namespace std;
int T,a,b,ans;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
		ans=0;
		for(int i=0;i<32;++i) ans+=((a&1)^(b&1))*(1<<i),a>>=1,b>>=1;
		cout<<ans<<'\n';
	}
	return 0;
}