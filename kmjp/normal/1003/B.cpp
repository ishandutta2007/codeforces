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

int A,B,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>X;
	int sw=0;
	if(A<B) {
		sw=1;
		swap(A,B);
	}
	string S(A,'0');
	while(X>2 || (X==2 && B==1)) {
		X-=2;
		FOR(i,S.size()-1) {
			if(S[i]=='0' && S[i+1]=='0') {
				S=S.substr(0,i+1)+"1"+S.substr(i+1);
				B--;
				break;
			}
		}
	}
	
	
	if(X) S+="1", X--, B--;
	if(X) S="1"+S, X--, B--;
	
	while(B--)  S+="1";
	if(sw) FORR(c,S) c^=1;
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}