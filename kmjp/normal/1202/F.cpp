#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")

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

ll A,B,C;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	C=A+B;
	ll ret=0;
	ll R=C;
	while(R>0) {
		ll H=C/R;
		ll L=C/(H+1)+1;
		ll AH=A/H;
		ll BH=B/H;
		ll AL=(A+H)/(H+1);
		ll BL=(B+H)/(H+1);
		if(AH>=AL && BH>=BL) {
			ret+=max(0LL,min(R,AH+BH)-max(L,AL+BL)+1);
			//cout<<L<<" "<<R<<" "<<ret<<endl;
		}
		R=L-1;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}