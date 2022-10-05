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

int Q;
int N,M,C,C0;
int T[505050],A[505050],B[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d%d%d",&N,&M,&C,&C0);
		vector<vector<int>> ev;
		FOR(i,N) {
			scanf("%d%d%d",&T[i],&A[i],&B[i]);
			ev.push_back({T[i],B[i],i});
		}
		T[N]=0,A[N]=C0,B[N]=0;
		ev.push_back({M,0});
		sort(ALL(ev));
		int ct=0;
		ll ret=0;
		set<pair<int,int>> S;
		S.insert({0,N});
		int TL=C0;
		
		FORR(e,ev) {
			int t=e[0]-ct;
			TL-=t;
			ct=e[0];
			while(t) {
				if(S.empty()) {
					ret=-1;
					break;
				}
				auto it=S.begin();
				x=it->second;
				y=min(t,A[x]);
				ret+=1LL*B[x]*y;
				A[x]-=y;
				t-=y;
				if(A[x]==0) S.erase(S.begin());
			}
			if(ct==M || ret==-1) break;
			S.insert({B[e[2]],e[2]});
			TL+=A[e[2]];
			while(TL>C) {
				auto it=*S.rbegin();
				x=it.second;
				y=min(A[x],TL-C);
				A[x]-=y;
				TL-=y;
				if(A[x]) break;
				S.erase(it);
				
			}
			
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}