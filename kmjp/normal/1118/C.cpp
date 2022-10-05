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
int C[2020];
int A[20][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N*N) cin>>x, C[x]++;
	
	if(N%2==0) {
		j=0;
		FOR(i,2020) if(C[i]) {
			if(C[i]%4) return _P("NO\n");
			while(C[i]) {
				C[i]-=4;
				A[j/(N/2)][j%(N/2)]=i;
				j++;
			}
		}
		
		FOR(y,N/2) FOR(x,N/2) A[N-1-y][N-1-x]=A[N-1-y][x]=A[y][N-1-x]=A[y][x];
	}
	else {
		vector<int> V[5];
		FOR(i,2020) {
			while(C[i]>=4) V[4].push_back(i), C[i]-=4;
			while(C[i]>=2) V[2].push_back(i), C[i]-=2;
			while(C[i]>=1) V[1].push_back(i), C[i]-=1;
		}
		
		if(V[1].size()!=1) return _P("NO\n");
		if(V[2].size()>(N-1)) return _P("NO\n");
		while(V[2].size()<(N-1)&&V[4].size()) {
			V[2].push_back(V[4].back());
			V[2].push_back(V[4].back());
			V[4].pop_back();
		}
		if(V[2].size()!=(N-1)) return _P("NO\n");
		if(V[4].size()!=(N/2)*(N/2)) return _P("NO\n");
		A[N/2][N/2]=V[1][0];
		FOR(i,(N-1)/2) A[N/2][i]=A[N/2][N-1-i]=V[2][i];
		FOR(i,(N-1)/2) A[i][N/2]=A[N-1-i][N/2]=V[2][(N-1)/2+i];
		FOR(i,V[4].size()) {
			A[i/(N/2)][i%(N/2)]=V[4][i];
			A[N-1-i/(N/2)][i%(N/2)]=V[4][i];
			A[i/(N/2)][N-1-i%(N/2)]=V[4][i];
			A[N-1-i/(N/2)][N-1-i%(N/2)]=V[4][i];
		}
		
	}
	
	
	cout<<"YES"<<endl;
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}