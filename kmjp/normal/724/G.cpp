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

int N,M;
vector<pair<int,ll>> E[101010];
ll dist[202020];
ll ret;
int mo=1000000007;

vector<pair<ll,ll>> S;
int num;
ll D[65];
int p2[404040];

void pushpush(ll v) {
	FORR(r,S) {
		if(v & r.second) v ^= r.first;
	}
	if(v==0) return;
	ll msb=1;
	while(msb*2<=v) msb*=2;
	S.push_back({v,msb});
	int i=S.size()-1,j;
	while(i&&S[i]<S[i-1]) swap(S[i],S[i-1]),i--;
	FOR(j,S.size()) if(i!=j && (S[j].first&S[i].second)) S[j].first ^= S[i].first;
}

void dfs(int cur) {
	num++;
	int i;
	FOR(i,60) if(dist[cur]&(1LL<<i)) D[i]++;
	
	FORR(e,E[cur]) {
		if(dist[e.first]!=-1) {
			pushpush(dist[cur]^e.second^dist[e.first]);
		}
		else {
			dist[e.first]=dist[cur]^e.second;
			dfs(e.first);
		}
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		ll v;
		cin>>x>>y>>v;
		x--,y--;
		E[x].push_back({y,v});
		E[y].push_back({x,v});
	}
	
	p2[0]=1;
	FOR(i,400000) p2[i+1]=p2[i]*2%mo;
	
	MINUS(dist);
	FOR(i,N) if(dist[i]==-1) {
		S.clear();
		ZERO(D);
		num=0;
		dist[i]=0;
		dfs(i);
		
		if(num==1) continue;
		
		ll is=0;
		FORR(r,S) is |= r.first;
		
		FOR(x,60) {
			ll a=D[x];
			ll b=num-D[x];
			if(is & (1LL<<x)) ret += ((a*(a-1)/2)+((b*(b-1)/2))+a*b)%mo*p2[x+(S.size()-1)]%mo;
			else ret += a*b%mo*p2[x+S.size()]%mo;
		}
		ret %= mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}