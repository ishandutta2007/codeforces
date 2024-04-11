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
int A[1010];
int K;
int B[1010];
int TA,TB;
int S[501];
int sum[501];
int can[501][501];

vector<pair<int,char>> R;


int dodo(int L,int R) {
	int i;
	
	if(can[L][R]!=-1) return can[L][R];
	if(L==R) return L;
	can[L][R]=-2;
	
	for(i=L;i<=R;i++) {
		if(dodo(L,i)>=0 && dodo(i+1,R)>=0 && sum[i+1]-sum[L]!=sum[R+1]-sum[i+1]) {
			can[L][R]=i;
			break;
		}
	}
	return can[L][R];
}

void gogo(int L,int R) {
	if(L==R) return;
	int X=can[L][R];
	gogo(X+1,R);
	gogo(L,X);
	if(sum[X+1]-sum[L]>sum[R+1]-sum[X+1]) {
		_P("%d R\n",L+1);
	}
	else {
		_P("%d L\n",L+2);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], sum[i+1]=sum[i]+A[i];
	cin>>K;
	FOR(i,K) cin>>B[i], TB+=B[i];
	
	if(sum[N]!=TB) return _P("NO\n");
	x=0;
	FOR(i,K) {
		S[i+1]=S[i]+1;
		while(sum[S[i+1]]-sum[S[i]]<B[i]) S[i+1]++;
		if(sum[S[i+1]]-sum[S[i]]>B[i]) return _P("NO\n");
	}
	
	MINUS(can);
	for(i=K-1;i>=0;i--) if(dodo(S[i],S[i+1]-1)==-2) return _P("NO\n");
	
	_P("YES\n");
	for(i=K-1;i>=0;i--) gogo(S[i],S[i+1]-1);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}