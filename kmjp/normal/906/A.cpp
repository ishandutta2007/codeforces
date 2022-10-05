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
int mask;
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	mask=(1<<26)-1;
	cin>>N;
	
	int ret=0;
	FOR(i,N) {
		cin>>S>>T;
		if(S=="!" || S==".") {
			if(S=="!" && __builtin_popcount(mask)==1) ret++;
			
			int tm=0;
			FORR(c,T) tm |= 1<<(c-'a');
			if(S=="!") mask &= tm;
			else mask &= ((1<<26)-1)^tm;
		}
		else {
			if(__builtin_popcount(mask)==1 && i!=N-1) ret++;
			x=T[0]-'a';
			if(mask & (1<<x)) mask^=1<<x;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}