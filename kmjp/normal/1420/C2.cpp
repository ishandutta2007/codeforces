#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int N,Q;
int A[303030];

int NV=1<<20;

ll val[2<<20][2][2];

void hoge(int a,int b,int c) {
	val[a][0][0]=-1LL<<60;
	val[a][0][1]=1LL<<60;
	val[a][1][0]=-1LL<<60;
	val[a][1][1]=1LL<<60;
	
	int i,j,k,l;
	FOR(i,2) FOR(j,2) FOR(k,2) FOR(l,2) {
		if(i==0) {
			val[a][(i+k)%2][0]=max(val[a][(i+k)%2][0],val[b][i][j]+val[c][k][l]);
			val[a][(i+k)%2][1]=min(val[a][(i+k)%2][1],val[b][i][j]+val[c][k][l]);
		}
		else {
			val[a][(i+k)%2][0]=max(val[a][(i+k)%2][0],val[b][i][j]-val[c][k][l]);
			val[a][(i+k)%2][1]=min(val[a][(i+k)%2][1],val[b][i][j]-val[c][k][l]);
		}
	}
}

void update(int entry, int v) {
	entry += NV;
	val[entry][0][0]=val[entry][0][1]=0;
	val[entry][1][0]=val[entry][1][1]=v;
	while(entry>1) {
		entry>>=1;
		hoge(entry,entry*2,entry*2+1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&Q);
		FOR(i,N) {
			scanf("%d",&A[i]);
			update(i,A[i]);
		}
		
		_P("%lld\n",max(val[1][0][0],val[1][1][0]));
		while(Q--) {
			int L,R;
			scanf("%d%d",&L,&R);
			L--,R--;
			swap(A[L],A[R]);
			update(L,A[L]);
			update(R,A[R]);
			_P("%lld\n",max(val[1][0][0],val[1][1][0]));
		}
		
		
		FOR(i,N) update(i,0);
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}