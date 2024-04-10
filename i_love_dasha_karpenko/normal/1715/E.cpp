//#prama GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pp;
#define endl '\n';
#define int ll
const int N = 1e5+7;
const ll INF = 1e18;
vector<pair<int,int> > G[N];
ll dist[N],nds[N];
ld inter(pair<ll,int> a,pair<ll,int> b){
	// a1*x+b1 = a2*x+b2
	// x*(a1-a2) = b2-b1
	return ld(b.second-a.second)/(a.first-b.first);
}
ll F(pair<int,ll> line,ll x){
	return x*line.first+line.second;
}
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i+=1){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > Q;
	for(int i = 1;i<=n;i+=1){
		dist[i] = INF;
	}

	dist[1] = 0;
	for(int step = 1;step<=k+1;step+=1){
		for(int i = 1;i<=n;i+=1){
			Q.push({dist[i],i});
		}
		while(!Q.empty()){
			ll ds = Q.top().first;
			int v = Q.top().second;
			Q.pop();
			if (dist[v]<ds){
				continue;
			}
			for(auto [to,w]:G[v]){
				if (dist[to]>dist[v]+w){
					dist[to] = dist[v] + w;
					Q.push({dist[to],to});
				}
			}
		}
		if (step==k+1){
			break;
		}
		for(int i = 1;i<=n;i+=1){
			nds[i] = dist[i];
		}
		// dist[i] = dist[j] + i^2 - 2*i*j + j^2
		// i*(-2j) + (dist[j] + j^2) + i^2
		for(int st = 0;st<2;st+=1){
			vector<pair<int,ll> > C;
			int ptr = 0;
			for(int i = 1;i<=n;i+=1){
				pair<int,ll> line = {-2*i,ll(i)*i + dist[i]};
				while(C.size()>1 && 
						inter(C[C.size()-2],C[C.size()-1])>=
						inter(C[C.size()-2],line)){
					C.pop_back();
				}
				C.push_back(line);
				ptr = min(ptr,int(C.size())-1);
				while(ptr+1<C.size() && F(C[ptr],i)>=F(C[ptr+1],i)){
					ptr += 1;
				}
				nds[i] = min(nds[i],F(C[ptr],i)+ll(i)*i);
			}
			for(int i = 1;i<n-i+1;i+=1){
				swap(nds[i],nds[n-i+1]);
				swap(dist[i],dist[n-i+1]);
			}
		}
		for(int i = 1;i<=n;i+=1){
			dist[i] = nds[i];
		}
	}
	for(int i = 1;i<=n;i+=1){
		cout<<dist[i]<<' ';
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}