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
int N,K;
set<int> E[202020],L[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) E[i].clear(),L[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		
		if(K==1) {
			cout<<N-1<<endl;
			continue;
		}
		if(N==2) {
			cout<<0<<endl;
			continue;
		}
		
		FOR(i,N) if(E[i].size()+L[i].size()==1) {
			if(E[i].size()) {
				x=*E[i].begin();
				E[i].erase(x);
				E[x].erase(i);
				L[x].insert(i);
			}
		}
		set<int> cand;
		FOR(i,N) if(L[i].size()&&L[i].size()%K==0&&E[i].size()==1) cand.insert(i);
		int num=0;
		while(cand.size()) {
			x=*cand.begin();
			cand.erase(x);
			num+=L[x].size()/K;
			L[x].clear();
			y=*E[x].begin();
			cand.erase(y);
			E[y].erase(x);
			L[y].insert(x);
			if(L[y].size()%K==0 && E[y].size()==1) cand.insert(y);
		}
		FOR(i,N) num+=L[i].size()/K;
		cout<<num<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}