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



const int FD=40;
int finddata[FD];
int find(int x) {
	if(finddata[x]==-1) return x;
	return finddata[x]=find(finddata[x]);
}


int N,M,Q;
int C[10][101010];
int NC;

const int NV=1<<17;
vector<int> val[NV*2];

vector<int> merge(vector<int> A, vector<int> B) {
	if(B.empty()) return A;
	if(A.empty()) return B;
	int NA=A[2*N+1],y;
	
	vector<int> R(2*N+4);
	R[2*N]=A[2*N]+B[2*N];
	R[2*N+2]=A[2*N+2];
	R[2*N+3]=B[2*N+3];
	
	MINUS(finddata);
	FOR(y,N) if(C[y][A[2*N+3]]==C[y][B[2*N+2]]) {
		int a=find(A[N+y]);
		int b=find(NA+B[y]);
		if(a!=b) {
			R[2*N]--;
			finddata[a]=b;
		}
	}
	
	int m[40]={},u=0;
	
	FOR(y,N) {
		if(m[find(A[y])]==0) m[find(A[y])]=++u;
		R[y]=m[find(A[y])]-1;
	}
	FOR(y,N) {
		if(m[find(NA+B[N+y])]==0) m[find(NA+B[N+y])]=++u;
		R[N+y]=m[find(NA+B[N+y])]-1;
	}
	R[2*N+1]=u;
	return R;
}

vector<int> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
	if(r<=x || y<=l) return {};
	if(x<=l && r<=y) return val[k];
	return merge(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	//cin>>N>>M>>Q;
	scanf("%d%d%d",&N,&M,&Q);
	FOR(y,N) FOR(x,M) scanf("%d",&C[y][x]);
	FOR(i,NV*2) val[i].resize(2*N+4);
	FOR(x,M) {
		for(y=1;y<N;y++) {
			if(C[y][x]==C[y-1][x]) val[NV+x][y]=val[NV+x][N+y]=val[NV+x][y-1];
			else val[NV+x][y]=val[NV+x][N+y]=val[NV+x][y-1]+1;
		}
		val[NV+x][2*N]=val[NV+x][2*N+1]=val[NV+x][N-1]+1;
		val[NV+x][2*N+2]=val[NV+x][2*N+3]=x;
	}
	for(i=NV-1;i>=1;i--) val[i]=merge(val[i*2],val[i*2+1]);
	FOR(i,Q) {
		scanf("%d%d",&x,&y);
		auto v=getval(x-1,y);
		_P("%d\n",v[2*N]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}