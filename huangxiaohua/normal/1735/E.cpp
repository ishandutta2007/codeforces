#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[10005],b[10005];
multiset<ll> sa0,sb0;

bool fuck(ll w){
	if(w<0)w=-w;
	multiset<ll> sa=sa0,sb=sb0;
	vector<pair<ll,ll> >res;
	ll nmsl1,nmsl2,mn=0;
	while(!sa.empty()||!sb.empty()){
		nmsl1=nmsl2=-1;
		if(!sa.empty())nmsl1=(*--sa.end());
		if(!sb.empty())nmsl2=(*--sb.end());
		if(max(nmsl1,nmsl2)<w)break;
		if(nmsl1>=nmsl2){
			auto it=sb.find(nmsl1-w);
			if(it==sb.end())return 0;
			sa.erase(sa.find(nmsl1)); sb.erase(it);
			res.push_back({nmsl1,nmsl1-w});
		}
		else{
			auto it=sa.find(nmsl2-w);
			if(it==sa.end())return 0;
			sa.erase(it); sb.erase(sb.find(nmsl2));
			res.push_back({nmsl2-w,nmsl2});
		}
	}
	for(auto i:sa){
		if(i>w)exit(1);
		auto it=sb.find(w-i);
		if(it==sb.end())return 0;
		sb.erase(it);
		res.push_back({i,w-i});
	}
	for(auto [i,j]:res){
		if(i<j&&i+j!=w)mn=max(mn,i);
	}
	cout<<"YES\n";
	for(auto [i,j]:res){
		if(i+j==w)cout<<mn+i<<' ';
		else if(i<j)cout<<mn-i<<' ';
		else cout<<mn+w+j<<' ';
	}
	cout<<'\n'<<mn<<' '<<mn+w<<'\n';
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		sa0.clear(); sb0.clear();
		for(i=1;i<=n;i++){
			cin>>a[i];
			sa0.insert(a[i]);
		}
		for(i=1;i<=n;i++){
			cin>>b[i];
			sb0.insert(b[i]);
		}
		for(i=1;i<=n;i++){
			if(fuck(a[1]+b[i])||fuck(a[1]-b[i])){
				goto aaa;
			}
		}
		cout<<"NO\n";
		aaa:;
	}
}