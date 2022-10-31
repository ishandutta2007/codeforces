#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
vector<pair<int,int> > v1,v2;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		v1.clear();
		v2.clear();
		ll res=0;
		for(i=1;i<=n;i++){
			cin>>k;
			if(k<i){
				v1.push_back({i,k});
				v2.push_back({k,i});
			}
		}
		if(v1.empty()){
			cout<<0<<'\n';continue;
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		reverse(v2.begin(),v2.end());
		for(auto [j,i]:v1){
			while(!v2.empty()){
				auto [x,y]=v2.back();
				if(x<=j)v2.pop_back();
				else break;
			}
			res+=v2.size();
		}
		cout<<res<<'\n';
	}
}