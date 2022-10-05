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

ll T;

int ask(ll A,ll B) {
	
	if(T) {
		return A%T>=B%T;
	}
	else {
		cout<<"? "<<A<<" "<<B<<endl;
		string x;
		cin>>x;
		
		
		if(x=="e") exit(0);
		return x=="x";
	}
}

void ans(ll a) {
	cout<<"! "<<a<<endl;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		cin>>s;
		if(s=="end") return;
		if(s=="mistake") return;
		
		if(ask(0,1)) {
			ans(1);
			continue;
		}
		
		ll A=1,B=2;
		while(1) {
			if(ask(A,B)) break;
			A*=2;
			B*=2;
		}
		
		while(B-A>1) {
			ll C=(A+B)/2;
			if(ask(A,C)) B=C;
			else A=C;
		}
		ans(A+1);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}