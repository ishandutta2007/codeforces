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
int A[202020];
int S[202020];

template<class C> int gf2_rank(vector<C>& V) { /* input */
	int i,j;
	int N=V.size();
	FOR(i,N) {
		sort(V.begin()+i,V.end(),greater<C>());
		if(V[i]==0) break;
		C msb=1;
		while(msb<<1 <= V[i]) msb<<=1;
		FOR(j,N) if(j!=i) if(V[j]&msb) V[j]^=V[i];
	}
	return N-count(V.begin(),V.end(),0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		S[i]=S[i-1]^A[i];
	}
	
	if(S[N]==0) return _P("-1\n");
	
	vector<int> C;
	int L=0,R=0;
	while(L<N) {
		for(R=L+1;R<N;R++) {
			x=S[R]^S[L];
			y=S[N]^S[R];
			vector<int> C2=C;
			C2.push_back(x);
			C2.push_back(y);
			if(gf2_rank(C2)!=C2.size()) continue;
			C.push_back(x);
			gf2_rank(C);
			break;
			
		}
		L=R;
	}
	
	cout<<C.size()+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}