#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,k;cin>>n>>k;
	int cx=0;
	for(int i=0;i<n;++i){
		cout<<(i^cx)<<endl;
		int r;cin>>r;
		if(r)break;
		cx^=(cx^i);
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}