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
int A[2525][2525];
bitset<2525> R[2525];
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	FOR(x,N) if(A[x][x]) return _P("NOT MAGIC\n");
	FOR(y,N) FOR(x,N) if(A[y][x]!=A[x][y]) return _P("NOT MAGIC\n");
	FOR(y,N) FOR(x,y) V.push_back({A[y][x],(y<<15)+x});
	sort(ALL(V));
	
	i=j=0;
	while(i<V.size()) {
		while(j<V.size() && V[j].first==V[i].first) {
			y=V[j].second>>15;
			x=V[j].second&0x3FFF;
			auto B=R[y] & R[x];
			if(B.any()) return _P("NOT MAGIC\n");
			j++;
		}
		while(i<j) {
			y=V[i].second>>15;
			x=V[i].second&0x3FFF;
			R[y].set(x,1);
			R[x].set(y,1);
			i++;
		}
	}
	
	_P("MAGIC\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}