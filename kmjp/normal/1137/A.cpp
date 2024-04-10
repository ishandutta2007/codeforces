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

int H,W;
int A[1010][1010];
vector<int> R[1010],C[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		R[y].push_back(A[y][x]);
		C[x].push_back(A[y][x]);
	}
	FOR(y,H) {
		sort(ALL(R[y]));
		R[y].erase(unique(ALL(R[y])),R[y].end());
	}
	FOR(x,W) {
		sort(ALL(C[x]));
		C[x].erase(unique(ALL(C[x])),C[x].end());
	}
	
	FOR(y,H) {
		FOR(x,W) {
			int ym=lower_bound(ALL(R[y]),A[y][x])-R[y].begin();
			int xm=lower_bound(ALL(C[x]),A[y][x])-C[x].begin();
			int mor=max(R[y].size()-(ym+1),C[x].size()-(xm+1));
			int le=max(ym,xm);
			cout<<(mor+le+1)<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}