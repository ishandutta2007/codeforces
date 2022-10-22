#include<bits/stdc++.h>
using namespace std;
string s;
int a,b,c;
int main(){
	int t;;
	cin>>t;
	while(t--){
		cin>>s;
		a=b=c=-1;
		int ans=998244353;
		for(int i=0;i<=s.length();++i){
			if(s[i]=='1')a=max(a,i);
			if(s[i]=='2')b=max(b,i);
			if(s[i]=='3')c=max(c,i);
			if(~a&&~b&&~c) ans=std::min(ans,i-std::min(a,std::min(b,c))+1);
		}
		if(ans<998244353){
			cout<<ans<<'\n';
		}
		else cout<<0<<'\n';
	}
	return 0;
}