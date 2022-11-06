#include<bits/stdc++.h>
using namespace std;
#define ERR(...) fprintf(stderr,__VA_ARGS__);
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
typedef long long ll;
const int MAXN=200005,MAXV=MAXN<<2;
const ll inf=1000000000000000000ll;
ll D[MAXV];int V[MAXV];
priority_queue<pair<ll,int> >Q;
template<class IT>inline void cmx(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmn(IT &a,IT b){if(b<a)a=b;}
template<class IT>inline bool bmx(IT &a,IT b){if(a<b){a=b;return true;}else return false;}
template<class IT>inline bool bmn(IT &a,IT b){if(b<a){a=b;return true;}else return false;}
inline void upd(int v,ll w){
	if(bmn(D[v],w))Q.push(make_pair(-w,v));
}
vector<pair<int,int> > E[MAXN];
#define REPE(i,a) for(i=(a).begin();i!=(a).end();++i)
#define PERE(i,a) for(i=(a).rbegin();i!=(a).rend();++i)
inline void ac(){
	int n,m,i,v,u,w;ll t;
	vector<pair<int,int> >::iterator e;
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&v,&u,&w);
		E[v].push_back(make_pair(u,w));
		E[u].push_back(make_pair(v,w));
	}
	rep(i,4,n<<2|3)D[i]=inf;
	Q.push(make_pair(D[7]=0ll,7));
	while(!Q.empty()){
		v=Q.top().second;
		t=-Q.top().first;
		Q.pop();
		if(V[v])continue;V[v]=1;
		//printf("v=%d\n",v);
		REPE(e,E[v>>2]){
			u=e->first;
			w=e->second;
			//printf("%d %d\n",u,w);
			upd(u<<2|(v&3),t+w);
			if(v&1)upd(u<<2|(v&2),t+(w<<1));
			if(v&2)upd(u<<2|(v&1),t);
			if((v&3)==3)upd(u<<2,t+w);
		}
	}
	rep(i,2,n)printf("%lld ",D[i<<2]);
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	ac();
	return 0;
}