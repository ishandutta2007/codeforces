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

int N,K;
bitset<606> from[505];
bitset<606> to[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	from[0][0]=1;
	FOR(i,N) {
		cin>>x;
		
		for(j=0;j<=K;j++) to[j] = from[j];
		for(j=0;j+x<=K;j++) {
			to[j+x] |= from[j];
			to[j+x] |= from[j]<<x;
		}
		swap(from,to);
	}
	vector<int> V;
	FOR(i,600) if(from[K][i]) V.push_back(i);
	_P("%d\n",V.size());
	FOR(i,V.size()) _P("%d%s",V[i],(i==V.size()-1)?"\n":" ");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}