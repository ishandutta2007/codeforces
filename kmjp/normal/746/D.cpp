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

ll N,K,A,B;
string R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>A>>B;
	
	if(A==B) {
		FOR(i,N/2) R+="GB";
	}
	else if(A<B) {
		if(B>(A+1)*K) return _P("NO\n");
		FOR(i,A+1) {
			FOR(x,B/(A+1)+(i<B%(A+1))) R+="B";
			if(i<A) R+="G";
		}
		
	}
	else if(B<A) {
		if(A>(B+1)*K) return _P("NO\n");
		FOR(i,B+1) {
			FOR(x,A/(B+1)+(i<A%(B+1))) R+="G";
			if(i<B) R+="B";
		}
	}
	cout<<R<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}