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
ll sum[202020];
int D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>D[i];
		sum[i+1]=sum[i]+x;
	}
	ll mi0=1<<30,ma1=-1<<30;
	FOR(i,N) {
		if(D[i]==1) mi0=min(mi0,sum[i]);
		if(D[i]==2) ma1=max(ma1,sum[i]);
	}
	if(mi0<=ma1) return _P("Impossible\n");
	if(ma1==-1<<30) return _P("Infinity\n");
	ll dif;
	FOR(i,N) if(D[i]==2 && ma1==sum[i]) dif=1899-ma1;
	cout<<dif+sum[N]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}