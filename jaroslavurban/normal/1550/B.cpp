#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	string s;
	int n,a,b;cin>>n>>a>>b>>s;
	if(b>0){
		cout<<a*n+b*n<<"\n";
		return;
	}
	int res=0;
	for(int i=1;i<n;++i)if(s[i]!=s[i-1])++res;
	cout<<a*n+b*(1+(res+1)/2)<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}