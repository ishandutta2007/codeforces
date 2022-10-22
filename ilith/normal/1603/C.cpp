#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<ll,ll>
#define fi first
#define se second
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define ROF(i,a,b) for(rgi i=a;i>=b;--i) 
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const ll N=300010,mod=998244353;
ll n,T,a[N],ans;
vector<pii>p,res;
void chk(ll x,ll c,ll w){
	int G=res.size();
	if(G&&x/c==res[G-1].fi){
		res[G-1].se+=w;
	}
	else res.pbk({x/c,w});
}
signed main(){
	for(scanf("%lld",&T);T--;){
		ans=0,p.clear();
		scanf("%lld",&n);
		FOR(i,1,n)scanf("%lld",a+i);
		ROF(i,n,1){
			res.clear();
			for(pii k:p){
				ll c=(a[i]-1)/k.fi;
				(ans+=c*k.se%mod*i)%=mod;
				chk(a[i],c+1,k.se);
			}
			chk(a[i],1,1),p=res;
		}
		printf("%lld\n",ans);
	}
	return 0;
}