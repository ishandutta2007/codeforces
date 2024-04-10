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
int A[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	int O=0;
	FOR(i,N-1) {
		if(S[i+1]=='a') {
			if(O==0) {
				O=1;
				A[i]=1;
				reverse(S.begin(),S.begin()+i+1);
			}
		}
		else {
			if(O==1) {
				O=0;
				A[i]=1;
				reverse(S.begin(),S.begin()+i+1);
			}
		}
	}
	if(O) {
		A[N-1]=1;
		reverse(ALL(S));
	}
	
	
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}