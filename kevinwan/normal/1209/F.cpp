#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e6+10;
vector<pii>g[mn];
bool vis[mn];
ll val[mn];
vector<int>gg[10];
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	int n,m;
	cin>>n>>m;
	int num=n;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		if(i<10){
			g[a].push_back({i,b});
			g[b].push_back({i,a});
			continue;
		}
		vector<int>v;
		for(int j=i;j;j/=10){
			v.push_back(j%10);
		}
		reverse(v.begin(),v.end());

		g[a].push_back({v[0],++num});
		for(int i=1;i+1<v.size();i++)g[num].push_back({v[i],++num});
		g[num].push_back({v.back(),b});

		g[b].push_back({v[0],++num});
		for(int i=1;i+1<v.size();i++)g[num].push_back({v[i],++num});
		g[num].push_back({v.back(),a});
	}
	for(int i=1;i<=num;i++)sort(g[i].begin(),g[i].end());
	queue<vector<int>>q;
	q.push({1});
	vis[1]=1;
	while(q.size()){
		cerr<<q.size()<<endl;
		auto v=q.front();
		q.pop();
		for(int i=0;i<10;i++)gg[i].clear();
		for(int x:v)for(pii p:g[x])gg[p.first].push_back(p.second);
		for(int i=0;i<10;i++){
			vector<int>nxt;
			for(int y:gg[i])if(!vis[y]){
				nxt.push_back(y);
				val[y]=(val[v[0]]*10+i)%mod;
				vis[y]=1;
			}
			if(nxt.size())q.push(nxt);
		}
	}
	for(int i=2;i<=n;i++)printf("%lld\n",val[i]);
}