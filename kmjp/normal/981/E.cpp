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


bitset<10101> B[10101];

int N,Q;


vector<int> V[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,10000) B[i][0]=1;
	FOR(i,Q) {
		cin>>x>>y>>r;
		x--;
		while(x<y && x%100) {
			B[x] |= B[x]<<r;
			x++;
		}
		while(x<y && y%100) {
			y--;
			B[y] |= B[y]<<r;
		}
		for(j=x/100;j<y/100;j++) {
			V[j].push_back(r);
		}
	}
	FOR(i,10000) B[i/100*100] |= B[i];
	FOR(i,100) {
		FORR(r,V[i]) B[i*100] |= B[i*100]<<r;
		B[10000] |= B[i*100];
	}
	vector<int> V;
	for(i=1;i<=N;i++) if(B[10000][i]) V.push_back(i);
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<" ";
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}