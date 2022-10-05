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

int H,W;
int G[505][505];
int R[505],C[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>G[y][x];
	vector<pair<int,int>> cand;
	for(R[0]=0;R[0]<=500;R[0]++) {
		FOR(x,W) C[x]=G[0][x]-R[0];
		for(y=1;y<H;y++) R[y]=G[y][0]-C[0];
		int ok=1;
		FOR(y,H) FOR(x,W) {
			if(R[y]<0 || C[x]<0) ok=0;
			if(R[y]+C[x]!=G[y][x]) ok=0;
		}
		if(ok==0) continue;
		int tot=0;
		FOR(y,H) tot+=R[y];
		FOR(x,W) tot+=C[x];
		cand.push_back({tot,R[0]});
	}
	
	sort(ALL(cand));
	if(cand.size()) {
		R[0]=cand[0].second;
		FOR(x,W) C[x]=G[0][x]-R[0];
		for(y=1;y<H;y++) R[y]=G[y][0]-C[0];
		_P("%d\n",cand[0].first);
		FOR(y,H) FOR(i,R[y]) _P("row %d\n",y+1);
		FOR(x,W) FOR(i,C[x]) _P("col %d\n",x+1);
	}
	else {
		_P("-1\n");
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}