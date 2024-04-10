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
map<pair<int,int>,set<int>> M;
int C[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-2) {
		int a,b,c;
		cin>>a>>b>>c;
		C[a]++;
		C[b]++;
		C[c]++;
		M[{min(b,c),max(b,c)}].insert(a);
		M[{min(a,c),max(a,c)}].insert(b);
		M[{min(a,b),max(a,b)}].insert(c);
	}
	
	vector<int> R;
	for(x=1;x<=N;x++) if(C[x]==1) break;
	for(y=1;y<=N;y++) if(C[y]==2 && (M.count({x,y}) || M.count({y,x}))) break;
	cout<<x<<" "<<y;
	N-=2;
	while(N) {
		int z=*M[{min(x,y),max(x,y)}].begin();
		M[{min(y,z),max(y,z)}].erase(x);
		cout<<" "<<z;
		x=y;
		y=z;
		N--;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}