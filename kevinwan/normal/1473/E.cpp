#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mn = 3e5+10;
const ll mod = 1e9+7;

vector<pii> g[mn];

ll dis[mn][4];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>>pq;
	pq.push({0,{1,0}});
	while(pq.size()){
		auto thing = pq.top();
		pq.pop();
		ll d=thing.first;
		pii p=thing.second;
		if(dis[p.first][p.second]!=0x3f3f3f3f3f3f3f3f)continue;
		dis[p.first][p.second]=d;
		for(pii nxt:g[p.first]){
			pq.push({d+nxt.second,{nxt.first,p.second}});
			if(p.second%2==0){
				pq.push({d+nxt.second*2,{nxt.first,p.second|1}});
			}
			if(p.second/2%2==0){
				pq.push({d,{nxt.first,p.second|2}});
			}
		}
	}
	for(int i=2;i<=n;i++)printf("%lld ",min(dis[i][3],dis[i][0]));
}