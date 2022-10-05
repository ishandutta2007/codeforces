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
int A[101010];
int C[101010];
set<pair<int,int>> S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>C[i];
		S.insert({C[i],i});
	}
	
	FOR(i,M) {
		cin>>x>>y;
		x--;
		ll ret=0;
		r=min(A[x],y);
		A[x]-=r;
		y-=r;
		ret+=1LL*C[x]*r;
		
		while(y && S.size()) {
			x=S.begin()->second;
			r=min(A[x],y);
			A[x]-=r;
			y-=r;
			ret+=1LL*C[x]*r;
			if(A[x]==0) S.erase(S.begin());
		}
		
		if(y>0) {
			cout<<0<<endl;
		}
		else {
			cout<<ret<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}