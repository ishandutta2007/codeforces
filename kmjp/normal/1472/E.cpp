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

int T,N;
int H[202020],W[202020];
int R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		map<int,vector<int>> M;
		cin>>N;
		FOR(i,N) {
			cin>>H[i]>>W[i];
			if(H[i]>W[i]) swap(H[i],W[i]);
			M[H[i]].push_back(i);
		}
		
		int mi=1<<30,ret=-1;
		FORR(m,M) {
			FORR(e,m.second) {
				if(mi<W[e]) R[e]=ret;
				else R[e]=-1;
			}
			FORR(e,m.second) if(W[e]<mi) mi=W[e], ret=e+1;
		}
		FOR(i,N) cout<<R[i]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}