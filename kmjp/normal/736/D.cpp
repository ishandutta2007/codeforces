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
vector<bitset<4096>> V;

template<unsigned int C> void trianglation(vector<bitset<C>>& A, int col) {
	int i,j,k,pos=0;
	int row=A.size();
	
	FOR(i,row) {
		while(1) {
			for(j=i;j<row;j++) {
				if(A[j][pos]) break;
			}
			if(j!=row) {
				swap(A[j],A[i]);
				break;
			}
			if(++pos==C) return;
		}
		FOR(j,row) if(j!=i && A[j][pos]) A[j]^=A[i];
	}
}
int A[505050],B[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	V.resize(N);
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		V[A[i]][B[i]]=1;
	}
	FOR(i,N) V[i][N+i]=1;
	trianglation(V,2*N);
	FOR(i,M) {
		if((bool)V[B[i]][N+A[i]]) _P("NO\n");
		else _P("YES\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}