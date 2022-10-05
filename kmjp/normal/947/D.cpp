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

char S[101010],T[101010];
int NS,NT;
int SX[101010],TX[101010];
int SA[101010],TA[101010];
int Q,A,B,C,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%s",S);
	scanf("%s",T);
	NS=strlen(S);
	NT=strlen(T);
	
	FOR(i,NS) {
		SX[i+1]=SX[i]+(S[i]!='A');
		SA[i+1]=(S[i]=='A')?SA[i]+1:0;
	}
	FOR(i,NT) {
		TX[i+1]=TX[i]+(T[i]!='A');
		TA[i+1]=(T[i]=='A')?TA[i]+1:0;
	}
	
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d%d%d",&A,&B,&C,&D);
		if(TA[D]>=D-C+1) {
			if(B-A>=D-C && ((B-A)-(D-C))%3==0 && SA[B]>=B-A+1) _P("1");
			else _P("0");
			continue;
		}
		if(TA[D]>min(SA[B],B-A+1)) {
			_P("0");
			continue;
		}
		B-=TA[D];
		D-=TA[D];
		
		if(B<A) {
			_P("0");
			continue;
		}
		if(TX[D]-TX[C-1]<SX[B]-SX[A-1]) {
			_P("0");
			continue;
		}
		if(TX[D]-TX[C-1]==SX[B]-SX[A-1] && SA[B]%3) {
			_P("0");
			continue;
		}
		if(((TX[D]-TX[C-1])-(SX[B]-SX[A-1]))%2) {
			_P("0");
			continue;
		}
		_P("1");
	}
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}