#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	string s;cin>>s;
	int n=s.size();
	int cnt[2][2]={};
	ll res=0;
	for(int i=0;i<n;++i){
		bool q=s[i]=='?';
		int madd=0;
		for(int j=0;j<2;++j){
			if(s[i]-'0'==j||q){
				s[i]=j+'0';
				int add=i+1-max(cnt[i&1][!(s[i]-'0')],cnt[!(i&1)][s[i]-'0']);
				madd=max(madd,add);
			}
		}
		res+=madd;
		if(!q)cnt[i&1][s[i]-'0']=i+1;
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}