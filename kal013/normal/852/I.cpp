#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> ostream& operator <<(ostream& os, vector<T> V){
	os << "[ "; for(auto v : V) os << v << " "; return os <<"]";
}
template<class L, class R> ostream& operator<<(ostream& os , pair<L, R> P){
	os <<"(" << P.first << " , " << P.second << ")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ',');
	cout.write(names, comma-names) << " : " << arg1 << " | ";
	__f(comma+1 , args...);
}
#else
#define trace(...) 1
#endif 
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pii pair<ll, ll>
#define vll vector<ll>
#define vi vector<ll>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
#define For(i,n) for(ll i = 0;i < n; i++)
#define Rep(i,n) for(ll i = 1;i <= n ;i++)


const ll maxn=1e5+100;
vi adj[maxn];

ll wt[maxn],tp[maxn];
ll tin[maxn],tout[maxn];
map<ll,ll> idx;

ll P[maxn],depth[maxn];
ll fp[maxn];
vector<pii> euler;

ll cnt[maxn][2];
void dfs(ll n,ll p){
	tin[n]=euler.size();
	P[n]=p;
	depth[n]=depth[p]+1;
	euler.pb({n,p});
	for(auto z:adj[n]){
		if (z!=p){
			dfs(z,n);
			euler.pb({z,n});
		}
	}
	tout[n]=euler.size();
}

ll ans[maxn];
const ll sz=230;
struct node{
	ll l, r, idx;
	ll lca;
	bool operator < (const node& n) const{
		if ((l/sz)==(n.l/sz)){
			if ((l/sz)&1){
				return (r>n.r);
			}
			else return r<n.r;
		}
		return ((l/sz)<(n.l/sz));
	}
};
node qry[maxn];
bool vis[maxn];
ll kol;
void add(ll i){
	ll n=euler[i].F;
	if (vis[n]){
		kol-=cnt[wt[n]][tp[n]^1];
		--cnt[wt[n]][tp[n]];
	}
	else{
		kol+=cnt[wt[n]][tp[n]^1];
		++cnt[wt[n]][tp[n]];
	}
	vis[n]=!vis[n];
}
inline ll LC(ll a,ll b){
	if (depth[b]<depth[a]) swap(a,b);
	// trace(fp[b],depth[fp[b]],depth[a]);
	// trace(a,b);
	while (depth[b]>depth[a]){
		if (depth[fp[b]]>=depth[a]) b=fp[b];
		else b=P[b];
	}
	// trace(a,b);
	// trace(a,b);
	while (a!=b){
		assert(depth[a]==depth[b]);
		if (fp[a]!=fp[b]){
			a=fp[a];
			b=fp[b];
		}
		else{
			a=P[a];
			b=P[b];
		}

	}
	return a;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << setprecision(25);
	ll n,u,v;
	cin>>n;
	kol=0;
	Rep(i,n){
		cin>>tp[i];
	}
	set<ll> comp;
	Rep(i,n){
		cin>>wt[i];
		comp.I(wt[i]);
	}
	ll cu=1;
	for(auto z:comp){
		idx[z]=cu++;
	}
	Rep(i,n) wt[i]=idx[wt[i]];
	For(i,n-1){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	depth[0]=0;
	P[0]=0;

	dfs(1,0);
	Rep(i,n){
		ll cu=i;
		Rep(j,sz) cu=P[cu];
		fp[i]=cu;
	}
	// trace(euler);
	euler.pb({1,0});
	// --tout[1];
	// Rep(i,n){
	// 	trace(i,tin[i],euler[tin[i]],euler[tout[i]]);
	// }
	ll q;
	cin>>q;
	For(i,q){
		cin>>u>>v;
		// trace(u,v,tin[u],tin[v]);

		if (tin[u]>tin[v]) swap(u,v);
		qry[i].l=tin[u];
		if (tout[u]<tin[v]) {qry[i].l=tout[u];			qry[i].lca=LC(u,v);

		}
		else{
			qry[i].lca=-1;

		}
		qry[i].r=tin[v];
		qry[i].idx=i;
	}
	sort(qry,qry+q);

	ll l=0,r=-1;

	For(i,q){
		ll L=qry[i].l,R=qry[i].r;
		while(r<R){
			add(++r);
		}
		while(r>R){
			add(r--);
		}
		while(l<L){
			add(l++);
		}
		while(l>L){
			add(--l);
		}
		// trace(l,r);
		ll res=0;
		if (qry[i].lca!=-1){

			ll x=qry[i].lca;
			// trace(x);
			res=cnt[wt[x]][tp[x]^1];
		}
		ans[qry[i].idx]=kol+res;

	}
	For(i,q){
		cout<<ans[i]<<endl;
	}

	return 0;
}