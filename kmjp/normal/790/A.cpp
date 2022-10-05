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

int N,K;
string S[101];
int A[101];
queue<string> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	x = -1;
	FOR(i,N-K+1) {
		cin>>s;
		A[i]=s=="YES";
		if(A[i] && x==-1) x=i;
	}
	
	FOR(i,25) {
		V.push(string("A") + (char)('a'+i));
		V.push(string("B") + (char)('a'+i));
	}
	
	if(x==-1) {
		FOR(i,N) cout<<"Aa ";
		cout<<endl;
	}
	else {
		FOR(i,K) S[i+x]=V.front(), V.pop();
		for(i=x+1;i<=N-K;i++) {
			if(A[i]) S[i+K-1]=V.front(), V.pop();
			else S[i+K-1]=S[i];
		}
		for(i=x-1;i>=0;i--) {
			if(A[i]) S[i]=V.front(), V.pop();
			else S[i]=S[i+K-1];
		}
		
		FOR(i,N) cout<<S[i]<<" ";
		cout<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}