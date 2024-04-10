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
int N,M;
vector<int> E[202020];
int mask[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			E[i].clear();
			mask[i]=0;
		}
		int K=4*N/7;
		
		FOR(i,M) {
			cin>>x>>y;
			x--,y--;
			E[x].push_back(y);
		}
		
		vector<int> cand;
		FOR(i,N) {
			if(mask[i]&2) {
				cand.push_back(i+1);
			}
			else if(mask[i]&1) {
				FORR(e,E[i]) mask[e]|=2;
			}
			else {
				FORR(e,E[i]) mask[e]|=1;
			}
		}
		
		assert(cand.size()<=K);
		cout<<cand.size()<<endl;
		FORR(c,cand) cout<<c<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}