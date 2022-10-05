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

int Q,N;
int X[101010],Y[101010],F[101010][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		int L=-100000,R=100000,U=100000,D=-100000;
		FOR(i,N) {
			cin>>X[i]>>Y[i]>>F[i][0]>>F[i][1]>>F[i][2]>>F[i][3];
			if(F[i][0]==0) L=max(X[i],L);
			if(F[i][1]==0) U=min(Y[i],U);
			if(F[i][2]==0) R=min(X[i],R);
			if(F[i][3]==0) D=max(Y[i],D);
		}
		
		if(L>R || D>U) {
			cout<<0<<endl;
		}
		else {
			cout<<"1 "<<L<<" "<<U<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}