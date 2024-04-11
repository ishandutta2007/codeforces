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
int C[303030];
ll tot[303030];
int tar[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	priority_queue<pair<int,int>> P;
	ll tot=0;
	for(i=1;i<=N+K;i++) {
		if(i<=N) {
			scanf("%d",&C[i]);
			P.push({C[i],i});
		}
		if(i>K) {
			auto a=P.top();
			P.pop();
			tot+=1LL*a.first*(i-a.second);
			tar[a.second]=i;
		}
	}
	
	printf("%" PRId64 "\n",tot);
	FOR(i,N) _P("%d%c",tar[i+1],(i==N-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}