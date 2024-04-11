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

string S;

int issq(int V) {
	int a=sqrt(V);
	if(a*a==V) return 1;
	if((a-1)*(a-1)==V) return 1;
	if((a+1)*(a+1)==V) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	int N=S.size();
	int mi=1010;
	for(int mask=1;mask<1<<N;mask++) {
		ll v=0;
		int first=-1;
		FOR(i,N) if(mask&(1<<i)) {
			v=v*10+S[i]-'0';
			if(first==-1) first=S[i]-'0';
		}
		if(first==0) continue;
		if(issq(v)) mi=min(mi,N-__builtin_popcount(mask));
	}
	
	if(mi==1010) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}