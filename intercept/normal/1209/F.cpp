#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=2e6+9;
const int mod=1e9+7;
int n,m;
int pre[M];
vector<pii>g[M];
bool vis[M];
int val[M];
int main(){
	cin>>n>>m;
	int num=n;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		int x=i,y=0;
		while(x){
			y=y*10+x%10;
			x/=10;
		}
		x=i;
		int w=u;
		for(int j=y;x/10;j/=10,x/=10){
			g[w].eb(++num,j%10);
			w=num;
		}
		g[w].eb(v,i%10);
		w=v;
		x=i;
		for(int j=y;x/10;j/=10,x/=10){
			g[w].eb(++num,j%10);
			w=num;
		}
		g[w].eb(u,i%10);
	}
	vector<pii>a;
	a={make_pair(1,1)};
	vector<vector<int>>b;
	while(a.size()){
		for(auto o:a){
			int u=o.se;
			for(auto v:g[u]){
				if(!vis[v.fi]){
					b.eb(vector<int>{o.fi*10+v.se,v.fi,u});
				}
			}
		}
		sort(b.begin(),b.end());
		int la=0,p=0;
		a.clear();
		for(auto o:b){
			if(vis[o[1]])continue;
			if(o[0]!=la)p++,la=o[0];
			vis[o[1]]=1;
			pre[o[1]]=o[2];
			val[o[1]]=(val[o[2]]*10ll+o[0]%10)%mod;
			a.eb(p,o[1]);
		}
		b.clear();
	}
	for(int i=2;i<=n;++i){
		cout<<val[i]<<"\n";
	}
	return 0;
}
/*
2 1
1 2
*/