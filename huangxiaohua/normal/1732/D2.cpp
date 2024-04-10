#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	map<ll,ll> f,mp;map<ll,set<ll> >vis,del;
	mp[0]=1;
	cin>>t;
	while(t--){
		string s;
		cin>>s>>k;
		if(s=="+"){
			for(auto i:vis[k])del[i].erase(k);
			mp[k]=1;
		}
		else if(s=="?"){
			while(mp[f[k]]){vis[f[k]].insert(k);f[k]+=k;}
			ll res=f[k];
			if(!del[k].empty())res=min(res,(ll)*del[k].begin());
			cout<<res<<'\n';
		}
		else{
			for(auto i:vis[k])del[i].insert(k);
			mp[k]=0;
		}
	}
}