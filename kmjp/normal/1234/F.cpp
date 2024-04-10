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
string S;

int ma[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,N) {
		int mask=0;
		for(j=i;j<N;j++) {
			if(mask & (1<<(S[j]-'a'))) break;
			mask |= (1<<(S[j]-'a'));
			ma[mask]=__builtin_popcount(mask);
		}
	}
	
	FOR(i,20) {
		FOR(j,1<<20) if(j&(1<<i)) ma[j]=max(ma[j],ma[j^(1<<i)]);
	}
	int ret=0;
	FOR(i,1<<20) ret=max(ret,ma[i]+ma[(1<<20)-1-i]);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}