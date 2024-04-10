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

ll N,S,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	
	if(S<K || (N-1)*K<S) return _P("NO\n");
	
	int cur=1;
	vector<int> V;
	while(K) {
		if(S>K) {
			int step=min(N-1,S-(K-1));
			if(cur==1) cur+=step;
			else cur-=step;
			S-=step;
		}
		else {
			if(cur==1) cur++;
			else cur--;
			S--;
		}
		V.push_back(cur);
		K--;
	}
	
	assert(K==0 && S==0);
	cout<<"YES"<<endl;
	FORR(v,V) cout<<v<<" ";
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}