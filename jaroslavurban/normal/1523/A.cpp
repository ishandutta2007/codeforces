#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=0,c=1;c&&i<m;++i){
		c=false;
		string ns=s;
		for(int j=0;j<n;++j)if(ns[j]=='0'){
			int l=j&&s[j-1]=='1';
			int r=j+1<n&&s[j+1]=='1';
			if(l+r==1)ns[j]='1',c=true;
		}
		swap(ns,s);
	}
	cout<<s<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}