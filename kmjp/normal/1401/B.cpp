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


int T;
ll X[2],Y[2],Z[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X[0]>>Y[0]>>Z[0];
		cin>>X[1]>>Y[1]>>Z[1];
		ll ret=0;
		x=min(Z[0],Y[1]);
		ret+=2*x;
		Z[0]-=x;
		Y[1]-=y;
		x=min(Z[1],X[0]);
		Z[1]-=x;
		X[0]-=x;
		x=min(Z[1],Z[0]);
		Z[0]-=x;
		Z[1]-=x;
		x=min(Y[1],X[0]);
		Y[1]-=x;
		X[0]-=x;
		
		
		ret-=2*min(Z[1],Y[0]);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}