#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		int n=s.size();
		if(s.size()%2){cout<<"NO\n";continue;}
		int l=0,r=0;
		for(int i=0;i<n;++i){
			if(s[i]=='(')l=i;
			if(s[i]==')')r=i;
		}
		if(l>r){
			if(s[0]!=')'&&s.back()!='(')cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}
}