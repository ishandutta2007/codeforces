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

int T;
int N,M;
int A[202020],B[202020];
ll S[202020];
int L[202020],R[202020];
vector<int> E[202020];
set<int> vis;

void hoge(int L,int R) {
	vector<int> C;
	while(1) {
		auto it=vis.lower_bound(L);
		if(it==vis.end()||*it>=R) break;
		C.push_back(*it);
		S[*it]=0;
		vis.erase(it);
	}
	FORR(c,C) FORR(e,E[c]) if(S[e]==0) hoge(min(c,e),max(e,c));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		
		
		FOR(i,N) {
			scanf("%d",&A[i]);
		}
		FOR(i,N) {
			scanf("%d",&B[i]);
			S[i+1]=S[i]+A[i]-B[i];
		}
		vis.clear();
		FOR(i,N+1) {
			vis.insert(i);
			E[i].clear();
		}
		
		
		queue<int> Q;
		FOR(i,M) {
			scanf("%d%d",&x,&y);
			x--;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		
		for(i=1;i<=N;i++) if(S[i]==0) {
			vis.erase(i);
			FORR(e,E[i]) if(S[e]==0) hoge(min(i,e),max(e,i));
		}
		FOR(i,N+1) if(S[i]) break;
		
		if(i==N+1) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}