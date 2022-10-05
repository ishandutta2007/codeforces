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
string S[1010],S2[1010];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	FOR(y,N) cin>>S[y];
	int ma=0;
	FOR(y,N) {
		FOR(x,N) S2[x]=S[x];
		FOR(x,N) if(S2[y][x]=='0') {
			FOR(z,N) S2[z][x]^=1;
		}
		r=0;
		FOR(x,N) if(count(S2[x].begin(),S2[x].begin()+N,'1')==N) r++;
		ma=max(ma,r);
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}