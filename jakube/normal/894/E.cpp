#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sqr(a) ((a)*(a))
#define rsz resize
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define PI 3.1415926535897932384626

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define MAXN 1000000
vector<ii> G[MAXN],gt[MAXN],condg[MAXN]; //Limpiar si se corre mas de una vez
//nodos 0...N-1 ; componentes 0...cantcomp-1
int comp[MAXN],N,cantcomp,used[MAXN];
ll sumcomp[MAXN];
stack<int> pila;
void add(int a, int b,int w){ G[a].pb(mp(b,w));gt[b].pb(mp(a,w));}
void dfs1(int nodo)
{
	used[nodo]=1;
	forall(it,G[nodo]) if(!used[it->fst]) dfs1(it->fst);
	pila.push(nodo);
}
void dfs2(int nodo)
{
	used[nodo]=2;
	comp[nodo]=cantcomp-1;
	forall(it,gt[nodo]) if(used[it->fst]!=2) dfs2(it->fst);
}
void kosaraju()
{
	cantcomp=0;
	forn(i,N) if(!used[i]) dfs1(i);
	while(!pila.empty())
	{
		if(used[pila.top()]!=2)
		{
			cantcomp++;
			dfs2(pila.top());
		}
		pila.pop();
	}
}

vector<ll> vaux,sum;

ll all(ll x)
{
	ll pos=ub(vaux.begin(),vaux.end(),x)-vaux.begin()-1;
	return (pos+1LL)*x-sum[pos];
}

ll dp[MAXN];

ll solve(int nodo)
{
	if(dp[nodo]) return dp[nodo]-1;
	//cout << nodo << "\n";
	ll ret=0;
	forall(it,condg[nodo]) ret=max(ret,solve(it->snd)+it->fst);
	//cout << nodo << ' ' << ret+sumcomp[nodo] << "\n";
	dp[nodo]=ret+sumcomp[nodo]+1;
	return ret+sumcomp[nodo];
}

int main()
{
	//freopen("input.in","r",stdin);
	//freopen("output","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,u,v,w,aux=2,acum=1,s,ans=0;
	vaux.pb(0);
	sum.pb(0);
	while(acum<=1e8)
	{
		vaux.pb(acum);
		sum.pb(sum[sum.size()-1]+acum);
		//if(acum<100) cout << acum << ' ' << sum[sum.size()-1] << "\n";
		acum+=aux;
		aux++;
	}
	//cout << all(100000000) << "\n";
	/*forr(i,10,50)
	{
		cout << "all " << i << ' ' << all(i) << " bf: ";
		int xxx=1,sxxx=0,j=i;
		while(j>0)
		{
			sxxx+=j;
			j-=xxx;
			xxx++;
		}
		cout << xxx << ' ' << sxxx << "\n";
	}*/
	cin >> n >> m;
	N=n;
	forn(i,m)
	{
		cin >> u >> v >> w;
		u--;v--;
		add(u,v,w);
	}
	kosaraju();
	//forn(i,n) cout << "comp " << i << ' ' << comp[i] << "\n";
	forn(i,n)forall(it,G[i])
	{
		if(comp[i]==comp[it->fst]) sumcomp[comp[i]]+=all(it->snd);
		else
		{
			//cout << comp[i] << "--" << it->snd << "-->" << comp[it->fst] << "\n";
			condg[comp[i]].pb(mp(it->snd,comp[it->fst]));
		}
	}
	//forn(i,cantcomp) cout << "sumcomp " << i << ' ' << sumcomp[i] << "\n";
	cin >> s;
	cout << solve(comp[s-1]) << "\n";

	return 0;
}