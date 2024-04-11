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

ll A[2][2];
ll n0,n1;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0][0]>>A[0][1]>>A[1][0]>>A[1][1];
	while(n0*(n0-1)/2<A[0][0]) n0++;
	while(n1*(n1-1)/2<A[1][1]) n1++;
	if(n0*(n0-1)/2!=A[0][0]) return _P("Impossible\n");
	if(n1*(n1-1)/2!=A[1][1]) return _P("Impossible\n");
	if(n0==0 && A[0][1]+A[1][0]) n0=1;
	if(n1==0 && A[0][1]+A[1][0]) n1=1;
	
	if(n0*n1 != A[0][1]+A[1][0]) return _P("Impossible\n");
	if(n0==0 && n1==0) return _P("0\n");
	if(n0==0 || n1==0) {
		FOR(i,max(n0,n1)) _P("%d",n0==0);
		_P("\n");
		return;
	}
	int post=A[0][1]/n0;
	int pre=n1-post;
	A[0][1] -= post*n0;
	string S=string(pre,'1')+string(n0,'0')+string(post,'1');
	FOR(i,S.size()) {
		if(S[i]=='0') {
			while(A[0][1]) {
				A[0][1]--;
				swap(S[i-1],S[i]);
				i++;
			}
			break;
		}
	}
	
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}