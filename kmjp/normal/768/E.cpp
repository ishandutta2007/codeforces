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

map<ll,int> memo[61];

int go(int cur,ll mask) {
	if(cur==0) return 0;
	
	mask &= (1LL<<(cur+1))-1;
	if(memo[cur].count(mask)) return memo[cur][mask];
	
	int mex=0;
	set<int> SS;
	int i;
	for(i=1;i<=cur;i++) if((mask&(1LL<<i))==0) {
		SS.insert(go(cur-i,mask | (1LL<<i)));
	}
	
	while(SS.count(mex)) mex++;
	return memo[cur][mask]=mex;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=60;i++) go(i,0);
	
	int nim=0;
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&x), nim^=memo[x][0];
	
	if(nim==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}