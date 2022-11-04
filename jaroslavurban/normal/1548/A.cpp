#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,m,cnt=0;cin>>n>>m;
	vector<int>out(n);
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		if(!out[min(u,v)]++)++cnt;
	}
	int q;cin>>q;
	while(q--){
		int t,u,v;cin>>t;
		if(t==1){
			cin>>u>>v;--u;--v;
			if(!out[min(u,v)]++)++cnt;
		}else if(t==2){
			cin>>u>>v;--u;--v;
			if(!--out[min(u,v)])--cnt;
		}else cout<<n-cnt<<"\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	//cin>>tc;
	while(tc--)ProGamerMove();
}