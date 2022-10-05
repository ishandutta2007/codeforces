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
int B[202020];
int C[202020];
int L[202020],R[202020];
int pos[202020],preR[202020];

int best=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		B[i]=A[i]+(N-1-i);
		C[i]=(1<<30)-(A[i]+(N-i));
	}
	FOR(i,N+5) L[i]=R[i]=(1<<30);
	
	for(i=N-1;i>=1;i--) {
		pos[i]=lower_bound(R,R+(N+1),C[i]+1)-R;
		preR[i]=R[pos[i]];
		R[pos[i]]=C[i];
		best=max(best,pos[i]+1);
	}
	int prex;
	FOR(i,N) {
		x=lower_bound(L,L+(N+1),B[i]+1)-L;
		L[x]=B[i];
		best=max(best,x+1);
		if(i<N-1) {
			R[pos[i+1]]=preR[i+1];
			y=0;
			for(j=20;j>=0;j--) if(y+(1<<j)<=N && ((1<<30)-R[y+(1<<j)-1])>=L[x]) y+=(1<<j);
			best=max(best,x+1+y);
			
			x=pos[i+1];
			y=0;
			for(j=20;j>=0;j--) if(y+(1<<j)<=N && ((1<<30)-R[x])>=L[y+(1<<j)-1]) y+=(1<<j);
			best=max(best,x+1+y);
			
			
		}
	}
	cout<<max(0,N-1-best)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}