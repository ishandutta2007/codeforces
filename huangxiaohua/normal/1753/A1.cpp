#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n&1){
			cout<<"-1\n";continue;
		}
		vector<pair<int,int> >v;
		for(i=1;i<=n;i+=2){
			if(a[i]==a[i+1])v.push_back({i,i+1});
			else{
				v.push_back({i,i});
				v.push_back({i+1,i+1});
			}
		}
		cout<<v.size()<<'\n';
		for(auto [i,j]:v){
			cout<<i<<' '<<j<<'\n';
		}
	}
}