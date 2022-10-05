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

ll U,V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>U>>V;
	if(U>V) return _P("-1\n");
	if(U%2!=V%2) return _P("-1\n");
	if(U==V) {
		if(U==0) {
			cout<<0<<endl;
		}
		else {
			cout<<1<<endl;
			cout<<U<<endl;
		}
		return;
	}
	ll A=(V-U)/2;
	if(((U+A)^A)==U) {
		cout<<2<<endl;
		cout<<A<<" "<<(A+U)<<endl;
	}
	else {
		cout<<3<<endl;
		cout<<U<<" "<<A<<" "<<A<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}