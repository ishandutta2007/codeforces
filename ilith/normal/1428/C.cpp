#include<bits/stdc++.h>
using namespace std;
string s;
signed main(){
	int T;cin>>T;
	while(T--) {
		cin>>s;
		int cnt=0,ans=0;
		for(int i=s.length()-1;i>=0;--i) {
			if(s[i]=='B') ++cnt;
			else {
				if(cnt>0) --cnt;
				else ++ans;
			}
		} if(cnt&1) ++ans;
		cout<<ans<<endl;
	}
	return 0;
}