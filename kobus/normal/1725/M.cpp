#include "bits/stdc++.h"
#define MAXN 200009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;
 
typedef long long ll;
typedef pair<ll,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const ll B=1e16;
ll dis[MAXN];
vector<PII>adj[MAXN];
int main(){
    //~ freopen("file.in", "r", stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adj[u].pb(mp(v,w));
		adj[v+n].pb(mp(u+n,w));
	}
	for(int i=1;i<=n;i++)
		adj[i].pb(mp(i+n,0));
	for(int i=2;i<=n+n;i++)
		dis[i]=B;
	priority_queue<PII>q;
	q.push(mp(0,1));
	while(!q.empty()){
		ll val=-q.top().ff;
		int nd=q.top().ss;
		q.pop();
		if(dis[nd]!=val)
			continue;
		for(auto to:adj[nd])
			if(umin(dis[to.ff],dis[nd]+to.ss))
				q.push(mp(-dis[to.ff],to.ff));
	}
	for(int i=2;i<=n;i++){
		if(dis[i+n]==B)
			printf("-1 ");
		else
			printf("%lld ",dis[i+n]);
	}
	puts("");
	return 0;
	
}