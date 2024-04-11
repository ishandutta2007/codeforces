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

int N,Q;
ll A[5050];

int val[5050][5050];
int ma[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		val[i][1]=ma[i][1]=A[i];
	}
	for(int len=2;len<=N;len++) {
		for(i=0;i+len<=N;i++) {
			val[i][len]=val[i][len-1]^val[i+1][len-1];
			ma[i][len]=max({val[i][len],ma[i][len-1],ma[i+1][len-1]});
		}
	}
		
	
	cin>>Q;
	while(Q--) {
		int L,R;
		cin>>L>>R;
		cout<<ma[L-1][R-L+1]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}