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
int X[101010];
int F[101010];
ll ret=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N+1) F[i]=1<<20;
	FOR(i,K) {
		cin>>X[i];
		F[X[i]]=min(i,F[X[i]]);
	}
	
	set<int> did;
	ll ret=0;
	if(N==1) ret=1;
	else {
		FOR(i,N) {
			if(i==0 || i==N-1) ret+=2;
			else ret+=3;
		}
	}
	for(i=K-1;i>=0;i--) {
		did.insert(X[i]);
		if(F[X[i]]==i) {
			ret-=did.count(X[i]);
			ret-=did.count(X[i]-1);
			ret-=did.count(X[i]+1);
			
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