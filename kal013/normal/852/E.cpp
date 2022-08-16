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

const ll mod=1e9+7;




const ll maxn=2e5+100;
inline ll add(ll x,ll y){
	x+=y; return (x>=mod)?x-mod:x;
}
inline ll sub(ll x,ll y){
	x-=y;return (x<0)?x+mod:x;
}
inline ll mul(ll x,ll y){
	return (x*1ll*y)%mod;
}

ll fpow(ll x,ll y){
	if (!y) return 1;

	ll ret=1;

	while(y){
		if ((y%2)==1) ret=mul(ret,x);
		y/=2;
		x=mul(x,x);
	}
	return ret;
}

ll inv(ll x){
	return fpow(x,mod-2);
}

ll dp[maxn][2],dp2[maxn][2];
ll prf[maxn][2];
vll adj[maxn];
void dfs(ll n,ll p){
	prf[n][0]=prf[n][1]=1;
	ll cntchil=0;
	for(auto x:adj[n]){
		if (x==p) continue;
		++cntchil;
		dfs(x,n);
		prf[n][0]=mul(prf[n][0],dp[x][0]);
		prf[n][1]=mul(prf[n][1],dp[x][1]);
	}
	if (cntchil==0){
		For(j,2) dp[n][j]=prf[n][j];
	}
	else{
		For(j,2) {
			dp[n][j]=add(prf[n][0],prf[n][1]);
		}
	}
	
}

void dfs2(ll n,ll p,pll X){
	dp2[n][0]=X.F;dp2[n][1]=X.S;
	// trace(n,p,X,dp2[n][0],dp2[n][1]);
	for(auto e:adj[n]){
		if (e==p) continue;

		ll tmp0=mul(prf[n][0],inv(dp[e][0]));
		ll tmp1=mul(prf[n][1],inv(dp[e][1]));
		// if (p==0 && ad)
		tmp0=mul(X.F,tmp0);
		tmp1=mul(X.F,tmp1);
		dfs2(e,n,{add(tmp0,tmp1),add(tmp0,tmp1)});
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << setprecision(25);
	ll n,u,v;
	cin>>n;


	For(i,n-1){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (n==1){
		cout<<1<<endl;
		return 0;
	}
	if (n==2){
		cout<<4<<endl;
		return 0;
	}
	ll root=0;
	for(root=1;root<=n;++root){
		if (adj[root].size()>1) break;
	}
	// trace(root);
	dfs(root,0);
	// Rep(i,n){
	// 	trace(dp[i][0],dp[i][1]);
	// }
	pll tmp;
	tmp={1,1};

	dfs2(root,0,tmp);

	ll res=0;


	Rep(i,n){
		res=add(res,mul(prf[i][0],dp2[i][0]));
		res=add(res,mul(prf[i][1],dp2[i][1]));
		// trace(res);
		// trace(n,res,prf[n][0],prf[n][1],dp2[n][0],dp2[n][1]);
	}

	cout<<res<<endl;

	return 0;
}