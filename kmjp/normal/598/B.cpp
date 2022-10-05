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

char S[30030];
char T[30030];
int M,L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=strlen(S);
	cin>>M;
	while(M--) {
		cin>>l>>r>>x;
		l--,r--;
		memmove(T,S,sizeof(S));
		FOR(i,r-l+1) S[l+(i+x)%(r-l+1)]=T[l+i];
	}
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}