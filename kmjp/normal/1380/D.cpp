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
ll X,K,Y;
int A[202020],B[202020];
int P[202020];

ll hoge(int L,int R,int la) {
	int mo=0;
	int i;
	ll ret=0;
	for(i=L;i<=R;i++) if(A[i]>la) mo++;
	int x=R-L+1;
	ret+=x%K*Y;
	x/=K;
	
	if(mo==0) {
		ret+=min(x*X,x*K*Y);
	}
	else {
		if(x==0) {
			cout<<-1<<endl;
			exit(0);
		}
		ret+=X;
		x--;
		ret+=min(x*X,x*K*Y);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>X>>K>>Y;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i];
	x=0;
	FOR(i,N) {
		if(x<M && A[i]==B[x]) {
			P[x]=i;
			x++;
		}
	}
	if(x!=M) return _P("-1\n");
	
	ll ret=hoge(0,P[0]-1,B[0]);
	FOR(i,M-1) {
		ret+=hoge(P[i]+1,P[i+1]-1,max(B[i],B[i+1]));
	}
	ret+=hoge(P[M-1]+1,N-1,B[M-1]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}