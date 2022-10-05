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

int N,X;
int A[1010101];
int L[1010101],R[1010101];
int LL[1010101],RR[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&X);
	FOR(i,X+1) {
		L[i]=N;
		R[i]=-1;
	}
	
	FOR(i,N) {
		scanf("%d",&x);
		R[x]=i;
		L[x]=min(L[x],i);
	}
	RR[0]=-1;
	for(x=1;x<=X;x++) {
		if(L[x]<RR[x-1]) RR[x]=N+1;
		else RR[x]=max(R[x],RR[x-1]);
	}
	LL[X+1]=N;
	for(x=X;x>=1;x--) {
		if(R[x]>LL[x+1]) LL[x]=-2;
		else LL[x]=min(L[x],LL[x+1]);
	}
	ll ret=0;
	int rr=1;
	for(x=1;x<=X;x++) {
		if(RR[x-1]>=N) break;
		
		if(RR[x-1]<=LL[x+1]) {
			ret+=(X+1-x);
			continue;
		}
		
		rr=x;
		for(i=20;i>=0;i--) if(rr+(1<<i)<=X && RR[x-1]>LL[rr+(1<<i)]) rr+=1<<i;
		ret+=(X-rr+1);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}