#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int N = 1e6+10;
int a[N], b[N];
ll c[2][N], ans;
vi con[N];
ll C(ll x){return (x*(x-1))/2;}
void dfs(int s, int p){
	for(int v:con[s]){
		if(v==p)continue; dfs(v,s);
		c[b[s]^0][s]+=c[0][v];
		c[b[s]^1][s]+=c[1][v];
		if(b[s] == 0) ans -= c[0][v]*c[1][v];
		else ans -= (C(c[0][v])+C(c[1][v]));
	}
	if(!b[s]) ans += c[0][s]*c[1][s];
	else ans += C(c[0][s])+C(c[1][s]);
	ans += c[1][s];
	c[b[s]][s]++;
	// cerr<<s<<" "<<c[0][s]<<" "<<c[1][s]<<endl;
}
int main(){
	int n,u,v;
	sd(n);
	ll ret =0;
	rep(i,1,n+1) sd(a[i]),ret+=a[i];
	rep(i,0,n-1){
		sd(u), sd(v);
		con[u].eb(v);
		con[v].eb(u);
	}
	for(int i = 0;i<=20;i++){
		for(int j = 1;j<=n;j++) b[j] = ((a[j]>>i)&1);
		memset(c,0,sizeof c);
		ans =0;
		dfs(1,0);
		// cerr<<ans<<endl;
		ret += (ans*(1<<i));
	}
	cout<<ret;
}