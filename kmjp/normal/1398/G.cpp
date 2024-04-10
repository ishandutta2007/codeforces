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

int N,X,Y;
int A[202020];
int Q;
int L[202020];
int ret[505050];

bitset<202020> BS,CS;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,N+1) {
		cin>>A[i];
		BS[A[i]]=1;
	}
	FOR(i,N) CS |= BS>>A[i];
	
	
	MINUS(ret);
	for(i=1;i<=500000;i++) {
		if(i>Y&&i-Y<=X&&CS[i-Y]) {
			for(j=i;j<=500000;j+=i) ret[j]=i*2;
		}
	}
	
	
	cin>>Q;
	FOR(i,Q) {
		cin>>x;
		cout<<ret[x/2]<<" ";
		
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}