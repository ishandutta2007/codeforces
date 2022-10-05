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
map<ll,int> M;
vector<int> R[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>x, M[x]=1;
	
	FORR(m,M) {
		ll a=m.first;
		
		R[1].clear();
		R[1].push_back(a);
		FOR(i,31) {
			if(M.count(a+(1LL<<i))) {
				if(R[2].empty()) {
					R[2].push_back(a);
					R[2].push_back(a+(1LL<<i));
				}
				if(M.count(a+(2LL<<i)) && R[3].empty()) {
					R[3].push_back(a);
					R[3].push_back(a+(1LL<<i));
					R[3].push_back(a+(2LL<<i));
				}
			}
		}
	}
	
	for(i=3;i>=1;i--) if(R[i].size()) {
		cout<<i<<endl;
		FORR(v,R[i]) cout<<v<<" ";
		return;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}