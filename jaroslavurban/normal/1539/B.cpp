#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	string s;
	int n,q;cin>>n>>q>>s;
	vector<ll>len(n+1);
	for(int i=1;i<=n;++i)len[i]=len[i-1]+(s[i-1]-'a'+1);
	while(q--){
		int l,r;cin>>l>>r;--l;
		cout<<len[r]-len[l]<<"\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}