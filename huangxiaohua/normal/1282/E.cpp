#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,z,vis[200500];

struct sb{
	int x,y,z;
	int ty;
}s[200500];

map<pair<int,int>,set<int> >mp;

queue<int> q;

void add(int x,int y,int i){
	mp[{min(x,y),max(x,y)}].insert(i);
}

int chk(int x,int y){
	return mp[{min(x,y),max(x,y)}].size()==1;
}

void del(int x,int y,int k){
	pair<int,int> z={min(x,y),max(x,y)};
	mp[z].erase(k);
	for(auto i:mp[z]){
		s[i].ty++;
		if(s[i].ty>=2&&!vis[i]){
			q.push(i);vis[i]=1;
		}
	}
}

vector<int> v[200500];

void dfs(int x,int fa){
	cout<<x<<' ';
	for(auto i:v[x]){
		if(i!=fa&&i!=1)dfs(i,x);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		mp.clear();
		cin>>n;
		for(i=1;i<=n;i++)v[i].clear(),vis[i]=0;
		for(i=1;i<=n-2;i++){
			cin>>x>>y>>z;
			s[i]={x,y,z,0};
			add(x,y,i);
			add(x,z,i);
			add(y,z,i);
		}
		for(auto [i,j]:mp){
			if(j.size()==1){
				auto [x,y]=i;
				v[x].push_back(y);
				v[y].push_back(x);
			}
		}
		dfs(1,v[1][0]);
		cout<<'\n';
		
		for(i=1;i<=n-2;i++){
			auto [x,y,z,ty]=s[i];
			s[i].ty+=chk(x,y);
			s[i].ty+=chk(x,z);
			s[i].ty+=chk(y,z);
			
			if(s[i].ty>=2){
				q.push(i);
				vis[i]=1;
			}
		}
		while(!q.empty()){
			k=q.front();q.pop();
			cout<<k<<' ';
			auto [x,y,z,ty]=s[k];
			del(x,y,k);
			del(x,z,k);
			del(y,z,k);
		}
		
		cout<<'\n';
	}
}