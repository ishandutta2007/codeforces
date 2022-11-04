#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	string s;cin>>s;
	int n=s.size();
	int res=0,ones=0;
	for(int c='a';c<='z';++c){
		int cnt=count(s.begin(),s.end(),c);
		if(cnt==1)++ones;
		else if(cnt>1)++res;
	}
	cout<<res+ones/2<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}