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

void getP(int N) {
	vector<int> V;
	int i;
	
	
	
	if(N%2==0) {
		_P("YES\n");
		set<int> S;
		FOR(i,N) {
			V.push_back(((1<<20)-1)^(i+1));
			for(int j=19;j>=0;j--) {
				if((V.back()&(1<<j)) && (V.back()>N || S.count(V.back()))) V.back()^=1<<j;
			}
			S.insert(V.back());
		}
		FOR(i,N) _P("%d%c",V[i],(i==N-1)?'\n':' ');
		//FOR(i,N) _P("%d:%d%c",V[i]==(i+1),V[i]&(i+1),(i==N-1)?'\n':' ');
	}
	else {
		_P("NO\n");
	}
}

void getQ(int N) {
	
	if(N<6 || (N&(N-1))==0) return _P("NO\n");
	_P("YES\n");
	if(N==6) {
		_P("3 6 2 5 1 4\n");
		return;
	}
	vector<int> V={3,6,1,5,4,7,2};
	
	int i;
	for(i=8;i<=N;i++) V.push_back(i);
	int x=8;
	while(x<=V.back()) {
		rotate(V.begin()+x-1,V.begin()+x,V.begin()+min(2*x-1,N));
		x*=2;
	}
	
	V.resize(N);
	FOR(i,N) _P("%d%c",V[i],(i==N-1)?'\n':' ');
	//FOR(i,N) _P("%d:%d%c",V[i]==(i+1),V[i]&(i+1),(i==N-1)?'\n':' ');
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x;
	getP(x);
	getQ(x);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}