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
int num[102020];
int ret[101010];

void dfs(int L,int R,int S,int K) {
	if(K==0) {
		while(L<R) ret[L++]=S++;
		return;
	}
	K-=2;
	int M=(L+R)/2;
	dfs(L,M,S+(R-M),min(K,num[M-L]));
	dfs(M,R,S,max(K-num[M-L],0));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=101000;i++) {
		num[i]=2+num[i/2]+num[i-i/2];
	}
	cin>>N>>K;
	K--;
	if(K%2) return _P("-1\n");
	if(num[N]<K) return _P("-1\n");
	dfs(0,N,1,K);
	FOR(i,N) _P("%d%c",ret[i],(i==N-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}