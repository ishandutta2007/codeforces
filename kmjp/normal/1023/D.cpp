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

int N,Q;
int A[202020],C[202020];
int B[202020];
int L[202020],R[202020];
vector<int> add[202020];
vector<int> del[202020];
set<int> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	MINUS(L);
	MINUS(R);
	FOR(i,N) {
		cin>>A[i];
		if(L[A[i]]==-1) L[A[i]]=i;
		R[A[i]]=i;
	}
	
	for(i=1;i<=Q;i++) {
		if(L[i]>=0) {
			add[L[i]].push_back(i);
			del[R[i]].push_back(i);
		}
	}
	
	FOR(i,N) {
		FORR(e,add[i]) S.insert(e);
		if(S.size()) {
			B[i]=*S.rbegin();
		}
		FORR(e,del[i]) S.erase(e);
	}
	
	if(count(B,B+N,0)==N) {
		cout<<"YES"<<endl;
		FOR(i,N) cout<<Q<<" ";
		cout<<endl;
		return;
	}
	
	if(L[Q]==-1) {
		FOR(i,N) if(A[i]==0) {
			B[i]=Q;
			break;
		}
		if(i==N) return _P("NO\n");
	}
	
	
	x=0;
	FOR(i,N) {
		if(B[i]==0) B[i]=x;
		else x=B[i];
	}
	x=0;
	for(i=N-1;i>=0;i--) {
		if(B[i]==0) B[i]=x;
		else x=B[i];
	}
	FOR(i,N) if(A[i] && A[i]!=B[i]) return _P("NO\n");
	cout<<"YES"<<endl;
	FOR(i,N) cout<<B[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}