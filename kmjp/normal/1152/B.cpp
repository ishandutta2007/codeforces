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

int X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	vector<int> V;
	while(X&&((X+1)&X)) {
		x=0;
		FOR(i,30) {
			if((1<<i)>=X) break;
			if((X&(1<<i))==0) x=i;
		}
		
		if(X&((1<<x)-1)) {
			V.push_back(x+1);
		}
		else {
			V.push_back(x);
		}
		X ^= (1<<V.back())-1;
		X++;
	}
	
	cout<<2*V.size()<<endl;
	FORR(v,V) cout<<v<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}