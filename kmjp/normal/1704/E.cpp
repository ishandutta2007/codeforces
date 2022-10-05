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

int T,N,M;
int A[1010],B[1010];
vector<int> E[1010],RE[1010];
int in[1010];
int D[1010];
const ll mo=998244353;
int alive[1010];
vector<int> Ds[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>A[i];
			E[i].clear();
			RE[i].clear();
			in[i]=D[i]=0;
			Ds[i].clear();
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			RE[y-1].push_back(x-1);
			in[x-1]++;
		}
		queue<int> Q;
		FOR(i,N) if(in[i]==0) Q.push(i);
		vector<int> cand;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			Ds[D[x]].push_back(x);
			cand.push_back(x);
			FORR(e,RE[x]) {
				D[e]=max(D[e],D[x]+1);
				if(--in[e]==0) Q.push(e);
			}
		}
		
		ll ret=0;
		//1000
		FOR(j,1000) {
			if(*max_element(A,A+N)==0) break;
			ret++;
			FOR(i,N) B[i]=0;
			FOR(i,N) if(A[i]) {
				(B[i]+=A[i]-1);
				FORR(e,E[i]) B[e]++;
			}
			FOR(i,N) A[i]=B[i];
		}
		FOR(i,N) alive[i]=A[i]>0;
		
		while(1) {
			int mi=-1;
			FOR(i,N) if(alive[i]) {
				int ok=1;
				FORR(e,RE[i]) if(alive[e]) ok=0;
				if(ok) {
					if(mi==-1||A[mi]<A[i]) mi=i;
				}
			}
			if(mi==-1) break;
			
			ret+=A[mi];
			FOR(i,N) B[i]=A[i];
			FOR(i,N) if(alive[i]) {
				FORR(e,E[i]) (B[e]+=A[mi])%=mo;
				(B[i]+=mo-A[mi])%=mo;
			}
			swap(A,B);
			alive[mi]=0;
		}
		
		
		
		cout<<ret%mo<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}