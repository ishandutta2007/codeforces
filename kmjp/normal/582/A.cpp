#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
map<int,int> M;
vector<int> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N*N) cin>>x, M[-x]++;
	
	while(M.size()) {
		auto r=M.begin();
		if(r->second==0) {
			M.erase(r);
			continue;
		}
		
		x = -r->first;
		FORR(rr,R) M[-__gcd(x,rr)] -= 2;
		M[-x]--;
		R.push_back(x);
		if(M[-x]==0) M.erase(-x);
	}
	
	FORR(r,R) _P("%d ",r);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}