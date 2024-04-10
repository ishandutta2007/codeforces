#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[200500],res;
vector<ll> v[200500];
ll dfs(ll x,ll w){
	ll i,j,k,sz=v[x].size();
	res+=a[x]*w;
	//printf("NMSL%d %d %d %d\n",x,f,w,a[x]);
	if(!sz){
		return a[x];
	}
	priority_queue<ll> q;
	for(auto i:v[x]){
		q.push(dfs(i,w/sz));
	}
	j=w%sz;
	while(j--){
		res+=q.top();q.pop();
	}
	return q.top()+a[x];
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		for(i=2;i<=n;i++){
			cin>>j;
			v[j].push_back(i);
		}
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		res=0;
		dfs(1,m);
		cout<<res<<'\n';
	}
}