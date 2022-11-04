#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int s[4];
	for(int i=0;i<4;++i)cin>>s[i];
	if(min(s[0],s[1])>max(s[2],s[3])||min(s[2],s[3])>max(s[0],s[1]))cout<<"NO\n";
	else cout<<"YES\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}