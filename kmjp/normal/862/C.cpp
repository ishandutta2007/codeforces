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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(N==2 && K==0) return _P("NO\n");
	vector<int> V;
	
	int ret=0;
	if(N%2==1) {
		FOR(i,N-1) {
			x=(1<<19)+i;
			ret^=x;
			V.push_back(x);
		}
		V.push_back(ret^K);
	}
	else {
		FOR(i,(N-1)/4*4) {
			x=(1<<19)+i;
			ret^=x;
			V.push_back(x);
		}
		assert(ret==0);
		
		if(N%4==0) {
			V.push_back(1<<17);
			V.push_back((1<<17)+(1<<18));
			V.push_back((1<<18));
			V.push_back(K);
		}
		else {
			if(K==0) {
				V.back()+=1<<17;
				V.push_back(1<<17);
			}
			else {
				V.push_back(0);
			}
			V.push_back(K);
		}
	}
	_P("YES\n");
	sort(ALL(V));
	FOR(i,N) _P("%d%c",V[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}