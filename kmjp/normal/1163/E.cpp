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
int S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	
	for(y=20;y>=0;y--) {
		vector<vector<int>> V;
		FOR(i,N) {
			if(S[i]>=1<<y) continue;
			int lef=S[i];
			FORR(v,V) if(lef&(1<<v[2])) lef^=v[1];
			if(lef) {
				x=0;
				FOR(j,20) if(lef&(1<<j)) x=j;
				FORR(v,V) if(v[1]&(1<<x)) v[1]^=lef;
				V.push_back({S[i],lef,x});
			}
		}
		if(V.size()<y) continue;
		cout<<y<<endl;
		cout<<0;
		int cur=0;
		for(i=1;i<1<<y;i++) {
			FOR(j,y) if(i&(1<<j)) {
				cur ^= V[j][0];
				cout<<" "<<cur;
				break;
			}
		}
		cout<<endl;
		break;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}