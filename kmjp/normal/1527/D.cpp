#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int T,N;
set<int> E[202020];
ll ret[202020];
ll C[202020];
int P[202020];
int ng[202020];

int dfs(int cur,int pre) {
	P[cur]=pre;
	C[cur]=1;
	FORR(e,E[cur]) if(e!=pre) C[cur]+=dfs(e,cur);
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N+1) ret[i]=ng[i]=0;
		
		FOR(i,N-1) {
			cin>>x>>y;
			E[x].insert(y);
			E[y].insert(x);
		}
		dfs(0,0);
		
		ll sum=1;
		FORR(e,E[0]) ret[1]+=C[e]*sum, sum+=C[e];
		ret[0]=1LL*N*(N-1)/2-ret[1];
		
		x=y=0;
		ng[0]=1;
		int p=1;
		for(i=1;i<N;i++) {
			
			if(ng[i]==0) {
				k=i;
				while(ng[k]==0) {
					ng[k]=1;
					if(i==1) p=k;
					k=P[k];
					if(x==k) {
						x=i;
						break;
					}
					if(y==k) {
						y=i;
						break;
					}
				}
				if(x!=i&&y!=i) break;
			}
			ng[i]=1;
			
			if(x>y) swap(x,y);
			if(x==0) {
				ret[i+1]=(C[0]-C[p])*C[y];
			}
			else {
				ret[i+1]=C[x]*C[y];
			}
			ret[i]-=ret[i+1];
			
		}
		
		
		FOR(i,N+1) cout<<ret[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}