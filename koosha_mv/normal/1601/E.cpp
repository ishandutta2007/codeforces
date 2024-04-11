#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=6e5+99,lg=20,inf=1e9+9;

int n,k,q,m,a[N],ans[N],seg[N];
pair<int,ll> par[lg][N];
vector<pair<pair<int,int>,int > > s[N];

void build(){
	f(i,0,n) seg[i+n]=a[i];
	f_(i,n-1,1){
		seg[i]=min(seg[i*2+0],seg[i*2+1]);
	}
}
int Get(int l, int r){
	int ans=inf;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) minm(ans,seg[l++]);
		if (r&1) minm(ans,seg[--r]);
	}
	return ans;
}
void solve(int x){
	vector<int> v;
	for(int i=x;i<n;i+=k){
		v.pb(a[i]);
		if(i+k<n) v.pb(Get(i+1,i+k));
	}
	m=v.size();
	f(i,0,lg)
		par[i][m].F=m;
	f_(i,m-1,0){
		par[0][i].F=i+1;
		while(par[0][i].F<v.size() && v[par[0][i].F]>=v[i])
			par[0][i].F=par[0][par[0][i].F].F;
		par[0][i].S=(par[0][i].F+1)/2-(i+1)/2;
		par[0][i].S*=v[i];
		f(j,1,lg){
			int u=par[j-1][i].F;
			par[j][i]=mp(par[j-1][u].F,par[j-1][i].S+par[j-1][u].S);
		}
	}
	//eror(par[0][2].S);
	f(i,0,s[x].size()){
		int l=2*s[x][i].F.F,r=2*s[x][i].F.S,ind=s[x][i].S;
		ll res=0;
		//cout<<l<<" "<<r<<endl;
		f_(j,lg-1,0){
			if(par[j][l].F<=r){
		//		cout<<j<<" "<<l<<" : "<<par[j][l].S<<endl;
				res+=par[j][l].S;
				l=par[j][l].F;
			}
		}
		//cout<<l<<" "<<res<<endl;
		if(!v[l]) eror(2);
		if(!(r/2-(l+1)/2+1))eror(3);
		res+=1ll*v[l]*(r/2-(l+1)/2+1);
		ans[ind]=res;
	}
}

main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q>>k;
	f(i,0,n) cin>>a[i];
	f(i,0,q){
		int l,r;
		cin>>l>>r;
		l--,r--;
		s[l%k].pb(mp(mp(l/k,r/k-(r%k<l%k)),i));
	}
	build();
	f(i,0,k){
		solve(i);
	}
	//cout<<"ANS : ";
	f(i,0,q){
		cout<<ans[i]<<" ";
	}
}