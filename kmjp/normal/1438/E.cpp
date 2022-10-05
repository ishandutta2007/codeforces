#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[202020];
ll S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i]=A[i];
		if(i) S[i]+=S[i-1];
	}
	
	ll ret=0;
	FOR(i,N) {
		int R=i+2;
		if(R>=N) break;
		if((A[i]^A[R])==A[i+1]) ret++;
		while(R<N) {
			ll s=S[R]-S[i];
			if(s<=A[i]) {
				R++;
			}
			else {
				R=lower_bound(S+R+1,S+N,S[R]+s-A[i])-S;
			}
			if(R>=N) break;
			if((A[i]^A[R])==S[R-1]-S[i]) ret++;
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