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

int T;
char C;
ll V;
string Q;

int num[1<<18];

int conv(ll a) {
	int ret=0,i;
	FOR(i,18) {
		ret = ret*2 + a%2;
		a/=10;
	}
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		
		cin>>C;
		if(C=='+' || C=='-') {
			cin>>V;
			if(C=='+') num[conv(V)]++;
			if(C=='-') num[conv(V)]--;
		}
		else {
			cin>>Q;
			reverse(ALL(Q));
			int L=0,R=0;
			FORR(c,Q) L=L*2+(c-'0');
			FOR(i,18-Q.size()) L=L*2;
			cout<<num[L]<<endl;
			
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}