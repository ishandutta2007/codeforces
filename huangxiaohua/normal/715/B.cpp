#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll w[10050],f[10050],sb,st,ed,l,r,md;
bool vis[10050];
vector<pair<int,int> >v[1050];
vector<int> q;

void work(){
	priority_queue<pair<ll,ll> >q;
	q.push({0,st});
	memset(vis,0,sizeof(vis));
	memset(f,1,sizeof(f));
	f[st]=0;
	
	while(!q.empty()){
		auto [x,y]=q.top();q.pop();x=-x;
		if(vis[y])continue;
		f[y]=x;vis[y]=1;
		if(y==ed)return;
		for(auto [i,j]:v[y]){
			if(w[j]>1e9)continue;
			if(!vis[i])q.push({-x-w[j],i});
		}
	}
}

void ans(){
	cout<<"YES\n";
	for(int i=1;i<=n;i++){
		for(auto [j,k]:v[i]){
			if(i>j)continue;
			cout<<i-1<<' '<<j-1<<' '<<w[k]<<'\n';
		}
	}
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>sb>>st>>ed;st++;ed++;
	for(i=1;i<=m;i++){
		cin>>j>>k>>w[i];
		j++;k++;
		v[j].push_back({k,i});
		v[k].push_back({j,i});
		if(!w[i]){
			q.push_back(i);
			w[i]=1e10;
		}
	}
	work();
	if(f[ed]<sb){
		cout<<"NO";return 0;
	}
	if(f[ed]==sb)ans();
	for(auto i:q){
		w[i]=1;
		work();
		if(f[ed]>sb)continue;
		l=1;r=1e9;
		while(1){
			md=(l+r)/2;
			w[i]=md;
			work();
			if(f[ed]==sb)break;
			if(f[ed]<sb)l=md+1;
			else r=md-1;
		}
		
		ans();
	}
	cout<<"NO";
}