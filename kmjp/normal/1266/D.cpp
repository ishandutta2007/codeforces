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

int N,M;
ll D[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,M) {
		scanf("%d%d%d",&x,&y,&r);
		D[x-1]+=r;
		D[y-1]-=r;
	}
	
	vector<int> neg,pos;
	FOR(i,N) {
		if(D[i]>0) pos.push_back(i);
		if(D[i]<0) neg.push_back(i);
	}
	
	vector<vector<ll>> ret;
	FORR(p,pos) {
		while(D[p]) {
			x=neg.back();
			
			ll v=min(D[p],-D[x]);
			D[p]-=v;
			D[x]+=v;
			ret.push_back({p+1,x+1,v});
			if(D[x]==0) neg.pop_back();
		}
	}
	
	_P("%d\n",ret.size());
	FORR(r,ret) _P("%" PRId64 " %" PRId64 " %" PRId64 "\n",r[0],r[1],r[2]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}