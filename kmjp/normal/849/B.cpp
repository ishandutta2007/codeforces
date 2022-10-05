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
ll Y[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>Y[i],Y[i]*=2;
	
	for(i=1;i<N;i++) if((Y[i]-Y[0])%i==0) {
		ll dx=(Y[i]-Y[0])/i;
		ll y2=-1LL<<60;
		for(x=1;x<N;x++) {
			ll yy=Y[x]-x*dx;
			if(yy==Y[0]) continue;
			if(y2==-1LL<<60) y2=yy;
			if(y2!=yy) break;
		}
		if(x==N && y2!=-1LL<<60) return _P("Yes\n");
	}
	{
		ll dx=(Y[2]-Y[1]);
		ll y2=-1LL<<60;
		for(x=0;x<N;x++) {
			ll yy=Y[x]-x*dx;
			if(yy==Y[1]-dx) continue;
			if(y2==-1LL<<60) y2=yy;
			if(y2!=yy) break;
		}
		if(x==N && y2!=-1LL<<60) return _P("Yes\n");
	}
	
	_P("No\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}