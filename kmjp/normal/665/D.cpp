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
int A[1010];

const int prime_max = 2005000;
int NP,divp[prime_max];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>N;
	vector<int> V;
	int n1=0;
	FOR(i,N) {
		cin>>x;
		if(x==1) n1++;
		V.push_back(x);
	}
	if(n1>=2) {
		FORR(r,V) if(r>1 && divp[r+1]==0) {
			_P("%d\n%d",n1+1,r);
			FOR(i,n1) _P(" %d",1);
			return _P("\n");
		}
		_P("%d\n",n1);
		FOR(i,n1) _P("%d ",1);
		return _P("\n");
	}
	FOR(y,V.size()) FOR(x,y) if(divp[V[y]+V[x]]==0) return _P("2\n%d %d\n",V[x],V[y]);
	_P("1\n%d\n",V[0]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}