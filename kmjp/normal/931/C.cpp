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
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		V.push_back(x);
	}
	int dif=N;
	sort(ALL(V));
	if(V[0]+2!=V[N-1]) {
		_P("%d\n",N);
		FOR(i,N) _P("%d%c",V[i],(i==N-1)?'\n':' ');
		return;
	}
	int A=count(ALL(V),V[0]);
	int C=count(ALL(V),V[N-1]);
	int B=N-A-C;
	
	int same=N,best=A;
	for(x=0;x<=N;x++) {
		int z=x+C-A;
		int y=N-x-z;
		if(z<0 || y<0) continue;
		if(same>min(x,A)+min(y,B)+min(z,C)) {
			same=min(x,A)+min(y,B)+min(z,C);
			best=x;
		}
	}
	
	_P("%d\n",same);
	FOR(i,best) _P("%d ",V[0]);
	FOR(i,best+C-A) _P("%d ",V[N-1]);
	FOR(i,N-best-(best+C-A)) _P("%d ",V[0]+1);
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}