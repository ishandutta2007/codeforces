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
int X[202020];
ll sum[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>X[i];
	
	FOR(i,M-1) {
		x=min(X[i],X[i+1]);
		y=max(X[i],X[i+1]);
		x--,y--;
		if(x==y) continue;
		
		sum[0]+=y-x;
		sum[x]-=y-x;
		sum[x]+=y;
		sum[x+1]-=y;
		sum[x+1]+=y-x-1;
		sum[y]-=y-x-1;
		sum[y]+=x+1;
		sum[y+1]-=x+1;
		sum[y+1]+=y-x;
	}
	
	FOR(i,N) {
		if(i) sum[i]+=sum[i-1];
		cout<<sum[i]<<" ";
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}