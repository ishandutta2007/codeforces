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

int N,M,K,S;
int A[202020], B[202020], T[202020], C[202020], RA[1000100], RB[1000100];
vector<pair<int,int> > PP[2];
ll sum[2][202020];

ll num[202020];

int ok(int d,int out) {
	int j,x,y;
	
	
	FOR(j,PP[0].size()+1) {
		int x=K-j;
		if(x<0) break;
		if(x>PP[1].size()) continue;
		if(sum[0][j]*A[d]+sum[1][x]*B[d]<=S) {
			if(out) {
				_P("%d\n",d+1);
				FOR(y,j) _P("%d %d\n",PP[0][y].second,RA[A[d]]+1);
				FOR(y,x) _P("%d %d\n",PP[1][y].second,RB[B[d]]+1);
				exit(0);
			}
			return 1;
		}
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) if(i) {
		if(A[i]<A[i-1]) RA[A[i]]=i;
		else A[i]=A[i-1];
		if(B[i]<B[i-1]) RB[B[i]]=i;
		else B[i]=B[i-1];
	}
	FOR(i,M) {
		cin>>T[i]>>C[i];
		T[i]--;
		PP[T[i]].push_back({C[i],i+1});
	}
	sort(ALL(PP[0]));
	sort(ALL(PP[1]));
	
	MINUS(num);
	FOR(i,2) FOR(j,PP[i].size()) sum[i][j+1]=sum[i][j]+PP[i][j].first;
	
	if(ok(N-1,0)==0) return _P("-1\n");
	int d=N-1;
	for(i=20;i>=0;i--) if(d-(1<<i)>=0 && ok(d-(1<<i),0)) d-=1<<i;
	ok(d,1);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}