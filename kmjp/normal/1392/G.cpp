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

int N,M,K;
string S,T;
int L[1010101],R[1010101];
int to[20];
int SS[1010101],TT[1010101];

int lef[1<<20],ri[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(lef);
	cin>>N>>M>>K;
	cin>>S>>T;
	
	FOR(i,N) {
		cin>>L[i]>>R[i];
		L[i]--,R[i]--;
	}
	
	FOR(i,1<<20) {
		lef[i]=N+1;
		ri[i]=-1;
	}
	
	FOR(i,K) {
		to[i]=i;
		if(T[i]=='1') TT[0]|=1<<to[i];
		if(S[i]=='1') SS[0]|=1<<to[i];
		lef[SS[0]]=0;
		ri[TT[0]]=0;
	}
	
	FOR(i,N) {
		swap(to[L[i]],to[R[i]]);
		
		FOR(j,K) {
			if(T[j]=='1') TT[i+1]|=1<<to[j];
			if(S[j]=='1') SS[i+1]|=1<<to[j];
		}
		lef[SS[i+1]]=min(lef[SS[i+1]],i+1);
		ri[TT[i+1]]=i+1;
	}
	
	FOR(i,20) {
		FOR(x,1<<20) if(x&(1<<i)) {
			lef[x^(1<<i)]=min(lef[x^(1<<i)],lef[x]);
			ri[x^(1<<i)]=max(ri[x^(1<<i)],ri[x]);
		}
	}
	
	int ma=-1;
	FOR(i,1<<20) {
		if(__builtin_popcount(i)>ma && ri[i]-lef[i]>=M) {
			ma=__builtin_popcount(i);
			x=lef[i];
			y=ri[i];
		}
	}
	int A=count(ALL(S),'1')+count(ALL(T),'1');
	
	cout<<(2*ma+S.size()-A)<<endl;
	cout<<(x+1)<<" "<<(y)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}