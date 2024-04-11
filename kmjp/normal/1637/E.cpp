#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,M;
ll A[303030],X[303030],Y[303030];
set<pair<int,int>> NG;
vector<int> CP[303030];
vector<int> cand;
map<int,int> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		C.clear();
		
		FOR(i,N) {
			scanf("%d",&x);
			C[x]++;
		}
		
		cand.clear();
		NG.clear();
		FOR(i,M) {
			scanf("%d%d",&x,&y);
			NG.insert({min(x,y),max(x,y)});
		}
		FORR2(a,b,C) {
			CP[b].push_back(a);
			cand.push_back(b);
			NG.insert({a,a});
		}
		
		sort(ALL(cand));
		cand.erase(unique(ALL(cand)),cand.end());
		ll ret=0;
		
		FORR2(a,b,C) {
			FORR(c,cand) {
				int R=CP[c].size()-1;
				while(R>=0&&NG.count({min(a,CP[c][R]),max(a,CP[c][R])})) R--;
				if(R>=0) ret=max(ret,1LL*(b+c)*(a+CP[c][R]));
			}
		}
		
		cout<<ret<<endl;
		FORR2(a,b,C) {
			CP[b].clear();
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}