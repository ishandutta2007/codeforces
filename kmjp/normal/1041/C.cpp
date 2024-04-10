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

int N,M,D;
int A[202020];
set<pair<int,int>> S;
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>D;
	FOR(i,N) {
		cin>>A[i];
		S.insert({A[i],i});
	}
	
	int day=1,la=0;
	int mi=1;
	while(S.size()) {
		auto it=S.lower_bound({mi,0});
		if(it==S.end()) {
			day++;
			mi=1;
			continue;
		}
		la=day;
		ret[it->second]=day;
		mi=it->first+D+1;
		S.erase(it);
	}
	
	cout<<la<<endl;
	FOR(i,N) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}