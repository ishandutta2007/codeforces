#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l,r,NMSL,t1,t2;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		vector<pair<int,int> > f[2];
		map<pair<int,int>,int> mp;
		NMSL=0;
		
		cin>>n;
		for(i=1;i<=3;i++){
			cin>>l>>r;
			f[(l+r)&1].push_back({l,r});
			mp[{l,r}]=1;
		}
		
		if(mp[{1,1}]&&mp[{1,2}]&&mp[{2,1}]){
			NMSL=1; t1=1; t2=1;
		}
		if(mp[{1,n}]&&mp[{1,n-1}]&&mp[{2,n}]){
			NMSL=1; t1=1; t2=n;
		}
		if(mp[{n,1}]&&mp[{n,2}]&&mp[{n-1,1}]){
			NMSL=1; t1=n; t2=1;
		}
		if(mp[{n,n}]&&mp[{n,n-1}]&&mp[{n-1,n}]){
			NMSL=1; t1=n; t2=n;
		}
		
		
		cin>>l>>r;
		
		if(NMSL){
			if(l==t1||r==t2){
				cout<<"YES\n";
			}
			else cout<<"NO\n";
			continue;
		}
		
		k=((l+r)&1);
		if(f[k].size()==2){
			cout<<"YES\n";continue;
		}
		auto [x,y]=f[k][0];
		//printf("NMSL%d %d %d %d\n",x,y,l,r);
		
		if((abs(x-l)%2)||(abs(y-r)%2)){
			cout<<"NO\n";
		}
		else cout<<"YES\n";
	}
}