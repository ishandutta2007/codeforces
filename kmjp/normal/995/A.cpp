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

int N,K;
int A[55][55];
int C[55][55];
vector<vector<int>> V;

void add(int i,int r,int c) {
	int y,x;
	if(i==0) return;
	V.push_back({i,r+1,c+1});
	FOR(y,4) FOR(x,N) if(C[y][x]==i) {
		assert(abs(r-y)+abs(x-c)==1);
		assert(C[r][c]==0);
		swap(C[y][x],C[r][c]);
		return;
	}
	assert(0);
}

void out(){
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,4) FOR(x,N) {
		cin>>A[y][x];
		if(y==1||y==2) C[y][x]=A[y][x];
	}
	
	if(N==1) {
		if(K==2 && A[0][0]!=A[1][0]) return _P("-1\n");
		if(A[0][0]&&A[0][0]==C[2][0]) add(C[2][0],1,0);
		if(A[0][0]&&A[0][0]==C[1][0]) add(C[1][0],0,0);
		if(A[3][0]&&A[3][0]==C[1][0]) add(C[1][0],2,0);
		if(A[3][0]&&A[3][0]==C[2][0]) add(C[2][0],3,0);
		FOR(x,N) assert(A[0][x]==C[0][x]);
		FOR(x,N) assert(A[3][x]==C[3][x]);
		out();
	}
	
	FOR(i,2*N) {
		FOR(x,N) {
			if(A[0][x] && A[0][x]==C[1][x]) add(C[1][x],0,x);
			if(A[3][x] && A[3][x]==C[2][x]) add(C[2][x],3,x);
		}
		FOR(x,2*N) {
			int cy=x/N,cx;
			if(cy==0) cx=x;
			else cx=2*N-1-x;
			if(C[cy+1][cx]==0) break;
		}
		if(x==2*N) return _P("-1\n");
		FOR(j,2*N-1) {
			int cur=(j+x+2*N)%(2*N);
			int nex=(j+x+2*N+1)%(2*N);
			int cy=cur/N,cx;
			if(cy==0) cx=cur;
			else cx=2*N-1-cur;
			int ny=nex/N,nx;
			if(ny==0) nx=nex;
			else nx=2*N-1-nex;
			cy++;
			ny++;
			
			if(C[ny][nx]) add(C[ny][nx],cy,cx);
		}
	}
	FOR(x,N) assert(A[0][x]==C[0][x]);
	FOR(x,N) assert(A[3][x]==C[3][x]);
	out();
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}