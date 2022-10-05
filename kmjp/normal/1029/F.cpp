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

ll A,B,C,P;
vector<ll> D[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	P=1LL<<60;
	cin>>A>>B;
	C=A+B;
	
	for(ll a=1;a*a<=A;a++) if(A%a==0) D[0].push_back(a);
	for(ll a=1;a*a<=B;a++) if(B%a==0) D[1].push_back(a);
	
	x=y=-1;
	for(ll H=1;H*H<=C;H++) if(C%H==0) {
		ll W=C/H;
		
		while(x+1<D[0].size() && H>=D[0][x+1]) x++;
		while(y+1<D[1].size() && H>=D[1][y+1]) y++;
		
		if(x>=0 && A/D[0][x]<=W) P=min(P,2*(H+W));
		if(y>=0 && B/D[1][y]<=W) P=min(P,2*(H+W));
	}
	cout<<P<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}