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

int L,K;
string S;
int sum[101010];

int ok(int cur,int d) {
	int l=max(0,cur-d);
	int r=min(cur+d,L-1);
	return (sum[r+1]-sum[l])>=K+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>K>>S;
	FOR(i,L) sum[i+1]=sum[i]+(S[i]=='0');
	
	int mi=1<<30;
	FOR(i,L) if(S[i]=='0') {
		int ret=1<<20;
		for(j=19;j>=0;j--) if(ok(i,ret-(1<<j))) ret-=1<<j;
		mi=min(mi,ret);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}