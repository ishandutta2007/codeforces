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
	int A=0;
	FORR(c,S) {
		if(c=='(') A++;
		else A--;
	}
	if(A!=0) return _P("-1\n");
	
	int ret=0;
	FOR(i,N) {
		if(S[i]=='(') {
			A++;
		}
		else if(A>0) {
			A--;
		}
		else {
			for(j=i;j<N;j++) {
				if(S[j]=='(') A++;
				else A--;
				if(A==0) break;
			}
			ret+=j-i+1;
			i=j;
			
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