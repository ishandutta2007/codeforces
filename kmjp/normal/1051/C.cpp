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
int A[101];
int cnt[101];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		cnt[A[i]]++;
	}
	int n1=0,n3=0;
	FOR(i,101) {
		if(A[i]==1) n1++;
		if(A[i]>=3) n3++;
	}
	
	
	S.resize(N);
	x=0;
	FOR(i,N) if(cnt[A[i]]==1) {
		S[i]='A'+x;
		x^=1;
	}
	
	FOR(i,N) if(x==1 && cnt[A[i]]>=3) {
		S[i]='B';
		x=0;
	}
	if(x) return _P("NO\n");
	FOR(i,N) if(S[i]==0) S[i]='A';
	
	cout<<"YES"<<endl;
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}