#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	string s,t;
	int n;cin>>n>>s;
	t=s;
	sort(t.begin(),t.end());
	int res=0;
	for(int i=0;i<n;++i)if(s[i]!=t[i])++res;
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}