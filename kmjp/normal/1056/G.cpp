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

int N,M,B;
int S;
ll T;

vector<int> hist;
int vis[303030];

int nex(int S,ll T) {
	if(S<M) S+=T%N;
	else S+=N-T%N;
	return S%N;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	B=N-M;
	cin>>S>>T;
	S--;
	
	while(T%N) S=nex(S,T),T--;
	T/=N;
	
	MINUS(vis);
	FOR(i,T) {
		if(vis[S]!=-1) {
			int per=i-vis[S];
			S=hist[vis[S]+(T-i)%per];
			break;
		}
		vis[S]=i;
		hist.push_back(S);
		for(j=N-1;j>=0;j--) S=nex(S,j);
	}
	cout<<(S+1)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}