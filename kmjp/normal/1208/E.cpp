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

int N,W;
vector<int> V;
ll S[1010101];
ll QS[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&W);
	FOR(i,N) {
		scanf("%d",&x);
		V.resize(x);
		int ma=0;
		FOR(j,x) {
			scanf("%d",&V[j]);
			ma=max(ma,V[j]);
		}
		if(V.size()==W) {
			FOR(j,W) S[j]+=V[j];
		}
		else if(V.size()*2>W) {
			int d=W-V.size();
			deque<pair<int,int>> Q;
			Q.push_back({-1,0});
			V.push_back(0);
			FOR(j,W) {
				while(Q.size() && Q.front().first<j-d) Q.pop_front();
				if(j<V.size()) {
					while(Q.size() && Q.back().second<=V[j]) Q.pop_back();
					Q.push_back({j,V[j]});
				}
				S[j]+=Q.front().second;
			}
		}
		else {
			QS[V.size()]+=ma;
			QS[W-V.size()]-=ma;
			int ma=0;
			FOR(j,V.size()) {
				ma=max(ma,V[j]);
				S[j]+=ma;
			}
			ma=0;
			FOR(j,V.size()) {
				ma=max(ma,V[V.size()-1-j]);
				S[W-1-j]+=ma;
			}
		}
	}
	
	FOR(i,W) {
		if(i) QS[i]+=QS[i-1];
		cout<<(S[i]+QS[i])<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}