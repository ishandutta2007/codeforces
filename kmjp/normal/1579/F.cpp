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

int T,N,D,A[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&D);
		FOR(i,N) scanf("%d",&A[i]);
		int ret=0;
		FOR(i,__gcd(N,D)) {
			x=i;
			vector<int> V;
			while(1) {
				V.push_back(A[x]);
				x=(x+D)%N;
				if(x==i) break;
			}
			int cur=0;
			FOR(j,V.size()*2) {
				if(V[j%V.size()]==0) {
					ret=max(ret,cur);
					cur=0;
				}
				else {
					cur++;
				}
			}
			if(cur>V.size()) ret=1<<30;
			
			
		}
		if(ret>N) ret=-1;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}