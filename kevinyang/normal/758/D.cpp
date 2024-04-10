#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#endif

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int base;cin>>base;
	string s;cin>>s;
	int val=1,ans=0;
	while(!s.empty()){
		string t;
		//try all the lengths
		int sz=s.size();
		for(int i=1;i<=sz;i++){
			string ss=s.substr(sz-i);
			// cerr<<"ss is "<<ss<<"\n";
			if(ss[0]=='0'&&(int)ss.size()!=1){
				continue;
			}
			if((int)ss.size()>=10){
				break;
			}
			if(stoll(ss)<base){
				t=ss;
			}
			else{
				break;
			}
		}
		for(int i=0;i<(int)t.size();i++)s.pop_back();
		// cout<<t<<"\n";
		ans+=val*stoll(t);
		val*=base;
	}
	cout<<ans<<"\n";
}