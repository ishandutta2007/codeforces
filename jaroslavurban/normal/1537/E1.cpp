#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	vector<string>strs;
	int n,k;cin>>n>>k;
	string s;cin>>s;
	auto add=[&](int mx){
		strs.push_back("");
		for(int i=0,idx=0;i<k;++i,idx=(idx+1)%mx)strs.back()+=s[idx];
	};
	for(int i=0;i<n;++i)add(i+1);
	sort(strs.begin(),strs.end());
	cout<<strs[0]<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}