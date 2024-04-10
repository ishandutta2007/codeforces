#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		string s;cin>>s;
		vector<ll>pref(n),suf(n);
		ll sheep=0,moves=0;
		for(int i=0;i<n;++i){
			if(s[i]=='*')++sheep;
			if(s[i]=='.')moves+=sheep;
			pref[i]=moves;
		}
		sheep=0,moves=0;
		for(int i=n-1;i>=0;--i){
			if(s[i]=='*')++sheep;
			if(s[i]=='.')moves+=sheep;
			suf[i]=moves;
		}
		ll res=LLONG_MAX;
		for(int i=0;i<n;++i)res=min(res,pref[i]+suf[i]);
		cout<<res<<"\n";
	}
}