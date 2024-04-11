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
int U[1010101];
int D[1010101][2];
ll dist[1010101];
vector<int> V[1010101];
vector<ll> S[1010101];

ll tot(int pos,int left) {
	if(pos>N || left<=0) return 0;
	int x=lower_bound(ALL(V[pos]),left+dist[pos])-V[pos].begin();
	if(x==0) return 0;
	return (ll)(left+dist[pos])*x - S[pos][x-1];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N+1) U[i]=D[i][0]=D[i][1]=1<<25;
	for(i=1;i<=N-1;i++) {
		scanf("%d",&x);
		U[i+1]=D[(i+1)/2][(i+1)%2]=x;
		dist[i+1]=dist[(i+1)/2]+x;
	}
	
	for(i=N;i>=1;i--) {
		V[i].push_back(dist[i]);
		if(i*2+1<=N) {
			x=y=0;
			while(x<V[i*2].size()||y<V[i*2+1].size()) {
				if(x==V[i*2].size()) {
					V[i].push_back(V[i*2+1][y++]);
				}
				else if(y==V[i*2+1].size()) {
					V[i].push_back(V[i*2][x++]);
				}
				else {
					if(V[i*2][x]<=V[i*2+1][y]) V[i].push_back(V[i*2][x++]);
					else V[i].push_back(V[i*2+1][y++]);
				}
			}
		}
		else if(i*2<=N) {
			FORR(v,V[i*2]) V[i].push_back(v);
		}
		ll a=0;
		FORR(v,V[i]) {
			a+=v;
			S[i].push_back(a);
		}
	}
	
	while(M--) {
		int A,H;
		scanf("%d%d",&A,&H);
		ll ret=tot(A,H);
		while(A>1) {
			x=A/2;
			H-=U[A];
			if(H<=0) break;
			ret+=H;
			
			if(A%2==1) ret+=tot(x*2,H-D[x][0]);
			else ret+=tot(x*2+1,H-D[x][1]);
			A /= 2;
		}
		cout<<ret<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}