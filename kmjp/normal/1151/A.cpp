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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int mi=101010;
	int a,b,c,d;
	FOR(d,N) FOR(c,d) FOR(b,c) FOR(a,b) {
		x=0;
		x+=min(abs(S[a]-'A'),26-abs(S[a]-'A'));
		x+=min(abs(S[b]-'C'),26-abs(S[b]-'C'));
		x+=min(abs(S[c]-'T'),26-abs(S[c]-'T'));
		x+=min(abs(S[d]-'G'),26-abs(S[d]-'G'));
		if(b==a+1 && c==b+1 && d==c+1) mi=min(mi,x);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}