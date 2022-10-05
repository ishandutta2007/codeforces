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

int A1,A2,K1,K2,N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A1>>A2>>K1>>K2>>N;
	
	cout<<max(0,N-A1*(K1-1)-A2*(K2-1))<<" ";
	if(K1<K2) {
		if(N<=A1*K1) {
			cout<<N/K1<<endl;
		}
		else {
			cout<<A1+(N-A1*K1)/K2<<endl;
		}
	}
	else {
		if(N<=A2*K2) {
			cout<<N/K2<<endl;
		}
		else {
			cout<<A2+(N-A2*K2)/K1<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}