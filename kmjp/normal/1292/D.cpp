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
 
int N,NV;
ll num[15050],D[15050],ND[50505];
 
 
const int prime_max = 5001;
map<vector<int>,int> M[30303];
vector<int> prime;
int NP,divp[prime_max];
vector<int> V[15001];
 
void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=i;j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}
 
int vis[10101];
vector<pair<int,int>> E[101010];
ll ret;

void dfs(int cur,int d) {
	vis[cur]=1;
	ret+=1LL*d*num[cur];
	FORR(e,E[cur]) if(vis[e.first]==0) dfs(e.first, d+e.second);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	V[1].resize(NP);
	M[0][V[1]]=1;
	ND[0]=1;
	
	NV=5000;
	for(i=2;i<=5000;i++) {
		V[i]=V[i-1];
		D[i]=D[i-1];
		x=i;
		FOR(j,NP) {
			while(x%prime[j]==0) {
				V[i][j]++;
				D[i]++;
				x/=prime[j];
			}
		}
		M[D[i]][V[i]]=i;
		ND[D[i]]++;
		
		auto V2=V[i-1];
		int d=0;
		for(j=NP-1;j>=0;j--) {
			if(V[i][j]!=V[i-1][j]) {
				d+=V[i-1][j];
				j--;
				for(;j>=0;j--) V2[j]=0;
				break;
			}
			d+=V[i][j];
		}
		if(M[d].count(V2)==0) {
			NV++;
			V[NV]=V2;
			M[d][V2]=NV;
			D[NV]=d;
			ND[d]++;
		}
	}
	
	
	for(i=5000;i>=2;i--) if(vis[i]==0) {
		auto V2=V[i];
		vis[i]=1;
		int d=D[i];
		int cur=i;
		FOR(j,NP) {
			while(V2[j]) {
				V2[j]--;
				d--;
				if(ND[d] && M[d].count(V2)) {
					x=M[d][V2];
					E[cur].push_back({x,D[cur]-D[x]});
					E[x].push_back({cur,D[cur]-D[x]});
					cur=x;
					if(vis[cur]) {
						j=NP;
						break;
					}
					vis[cur]=1;
				}
			}
		}
	}
	

	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>x;
		if(x==0) x++;
		num[x]++;
	}
	
	ll mi=1LL<<60;
	for(i=1;i<=NV;i++) {
		ZERO(vis);
		ret=0;
		dfs(i,0);
		mi=min(mi,ret);
	}
	cout<<mi<<endl;
	
	
}
 
 
int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}