#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100;
vector<int>g[N];
unordered_map<int,vector<pair<int,int>>>cded;
unordered_map<int,int>activ;
unordered_map<int,int>rekt;
bool banned[N];
bool fucked[N];
int a[N];
int bn;
bool done;
bool zero;
int ru,rv;
unordered_set<int>found;

void ban(int u,int p,bool spec=false){
	if(banned[u])return;
	banned[u]=true;++bn;
	rekt[a[u]]=true;
	if(activ.count(a[u]))fucked[activ[a[u]]]=true;
	if(found.count(a[u]))zero=true;
	else found.insert(a[u]);
	for(auto v:g[u])if(v!=p)ban(v,u,spec);
	if(!spec)found.erase(a[u]);
}

void dfs(int u,int p){
	if(cded.count(a[u])){found.clear();ban(u,p);}
	if(activ.count(a[u])){found.clear();ban(u,p);}
	if(!cded.count(a[u])&&!activ.count(a[u])){
		activ[a[u]]=u;
		for(auto v:g[u])if(v!=p){
			dfs(v,u);
			if(done||zero)return;
			if(fucked[u]){
				found.clear();
				ru=u;rv=v;
				ban(u,v);
				done=true;
				return;
			}
		}
		cded[a[u]].push_back({u,p});
		activ.erase(a[u]);
	}
}

main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,0);
	for(auto it=cded.begin();it!=cded.end();++it)
		if(rekt[it->first])
			for(auto e:it->second)
				if(!zero)
					found.clear(),ban(e.first,e.second);
	int res=(zero?0:n-bn);
	if(!zero){
		found.clear();
		for(int i=0;i<n;++i)if(banned[i])found.insert(a[i]);
		ban(rv,ru,true);
		assert(bn==n);
		assert(!zero);
	}
	cout<<res<<endl;
}