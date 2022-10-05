#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
vector<pair<int,int>> EV[101010];
ll X[101010],C[101010];
int vis[101010];
int NV[101010];
ll mo=1000000007;
ll ret=1,retr=1;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e+=(1<<(ME-2));while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e+=(1<<(ME-2)); while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
template<class V, int ME> class BITm {
public:
	V bit[1<<ME];
	BITm(){ for(int i=0;i<1<<ME;i++) bit[i]=1;}
	V operator()(int e) {V s=1;e+=(1<<(ME-2));while(e) (s*=bit[e-1])%=mo,e-=e&-e; return s;}
	V add(int e,V v) { e+=(1<<(ME-2)); while(e<=1<<ME) (bit[e-1]*=v)%=mo,e+=e&-e;}
};

BIT<int,20> R2,B2;
BITm<ll,20> R2m,B2m;
vector<pair<pair<int,int>,ll>> evs,evt;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll rev(ll a) {
	ll r=1, n=mo-2;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,EV[cur]) if(e.first!=pre && vis[e.first]==0) NV[cur]+=dfs(e.first,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,EV[cur]) if(e.first!=pre && vis[e.first]==0) {
		int c = dfs2(e.first,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e.first];
		if(NV[e.first]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs3(int cur,int pre,int R,int B,ll V) {
	evt.push_back({{R,B},V});
	
	int x=2*R-B;
	
	(ret *= modpow(V,R2(x)))%=mo;
	(ret *= R2m(x))%=mo;
	
	x = 2*B-R;
	(retr *= modpow(V,B2(220000)-B2(x)))%=mo;
	(retr *= B2m(220000)*rev(B2m(x))%mo)%=mo;
	
	FORR(e,EV[cur]) if(e.first!=pre && vis[e.first]==0) dfs3(e.first,cur,R+(C[e.second]==0),B+(C[e.second]==1),V*X[e.second]%mo);
}

void split(int cur,int id) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	vis[center]=1;
	evs.push_back({{0,0},1});
	R2.add(0,1);
	B2.add(0,1);
	
	FORR(e,EV[center]) if(vis[e.first]==0) {
		dfs3(e.first,center,C[e.second]==0,C[e.second]==1,X[e.second]);
		
		FORR(r,evt) {
			evs.push_back(r);
			R2.add(-(r.first.first*2-r.first.second),1);
			R2m.add(-(r.first.first*2-r.first.second),r.second);
			B2.add(-(r.first.second*2-r.first.first),1);
			B2m.add(-(r.first.second*2-r.first.first),r.second);
		}
		evt.clear();
	}
	FORR(r,evs) {
		R2.add(-(r.first.first*2-r.first.second),-1);
		B2.add(-(r.first.second*2-r.first.first),-1);
		R2m.add(-(r.first.first*2-r.first.second),rev(r.second));
		B2m.add(-(r.first.second*2-r.first.first),rev(r.second));
	}
	evs.clear();
	FORR(e,EV[center]) if(vis[e.first]==0) split(e.first,id+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>X[i]>>C[i];
		EV[x-1].push_back({y-1,i});
		EV[y-1].push_back({x-1,i});
	}
	split(0,1);
	
	cout<<ret*rev(retr)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}