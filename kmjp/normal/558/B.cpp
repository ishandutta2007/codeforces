#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int L[1010101],R[1010101],num[1010101];
int ma;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(L);
	MINUS(R);
	FOR(i,N) {
		cin>>x;
		
		num[x]++;
		ma=max(ma,num[x]);
		if(L[x]==-1) L[x]=i;
		R[x]=i;
	}
	int LL=0,RR=N-1;
	FOR(i,1010101) if(num[i]==ma) {
		if(RR-LL > R[i]-L[i] || ((RR-LL==R[i]-L[i])&&L[i]<LL)) {
			LL=L[i];
			RR=R[i];
		}
	}
	_P("%d %d\n",LL+1,RR+1);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}