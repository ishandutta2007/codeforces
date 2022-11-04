#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	string s,t;cin>>s>>t;
	int n=s.size(),m=t.size();
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j){
			int k=m-(j-i+1);
			if(j-k<0||k<0)continue;
			string rght=s.substr(i,j-i+1);
			string lft=s.substr(j-k,k);
			reverse(lft.begin(),lft.end());
			if(t==rght+lft){
				cout<<"YES\n";
				return;
			}
		}
	}
	cout<<"NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}