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

int C,N;
int P[202020];
int pre[202020];
ll mi[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>C>>N;
	FOR(i,N) cin>>x, P[x]++;
	for(i=1;i<=C;i++) {
		if(P[i]) pre[i]=i;
		else pre[i]=pre[i-1];
	}
	
	for(i=1;i<=C;i++) {
		int did=0;
		int cur=C;
		int tar=pre[C];
		
		while(tar) {
			if(did==0 && tar<i&&cur>=i) {
				did=1;
				cur-=i;
				continue;
			}
			cur-=tar*min(P[tar],cur/tar);
			tar=min(pre[cur],pre[tar-1]);
		}
		if(cur) return _P("%d\n",i);
	}
	_P("Greed is good\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}