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
ll K,A[202020];
map<int,int> M[13];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	ll ret=0;
	FOR(i,N) {
		cin>>A[i];
		ll v=1;
		int x=1;
		while(v*10<=A[i]) x++, v*=10;
		M[x][A[i]%K]++;
		if((v*10+1)%K*A[i]%K==0) ret--;
	}
	FOR(i,N) {
		ll V=A[i]%K;
		for(j=1;j<=10;j++) {
			V=V*10;
			if(V>=K) V%=K;
			
			if(V==0) ret+=M[j][0];
			else ret+=M[j][K-V];
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