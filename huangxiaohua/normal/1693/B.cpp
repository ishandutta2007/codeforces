#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll l[200500],r[200500],res;
vector<int> v[200500];

void dfs(int x){
	if(v[x].empty()){
		res++;return;
	}
	ll su=0;
	for(auto i:v[x]){
		dfs(i);
		su+=r[i];
	}
	if(su>=l[x]){
		r[x]=min(r[x],su);
	}
	else{
		res++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)v[i].clear();
		res=0;
		for(i=2;i<=n;i++){
			cin>>k;v[k].push_back(i);
		}
		for(i=1;i<=n;i++){
			cin>>l[i]>>r[i];
		}
		dfs(1);
		cout<<res<<'\n';
	}
}