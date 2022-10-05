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

ll A1,B1,A2,B2,L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A1>>B1>>A2>>B2>>L>>R;
	L=max(L,max(B1,B2));
	if(L>R) return _P("0\n");
	
	if(A2==0) swap(A1,A2),swap(B1,B2);
	if(A1==0) {
		if(A2==0) return _P("%d\n", (B1==B2));
		return _P("%d\n",(B1>=B2) && ((B1-B2)%A2==0));
	}
	
	if(A2>=1000) swap(A1,A2),swap(B1,B2);
	if(A1>=1000) {
		ll ret=0;
		for(ll x=0;A1*x+B1<=R;x++) {
			if(A1*x+B1<L) continue;
			ll X=A1*x+B1 - B2;
			if(X%A2) continue;
			if(X/A2>=0) ret++;
		}
		cout<<ret<<endl;
		return;
	}
	
	FOR(i,1000001) {
		if(B1<L) B1 += (L-B1+A1-1)/A1*A1;
		if(B2<L) B2 += (L-B2+A2-1)/A2*A2;
		L=max(L,max(B1,B2));
		if(B1==L && B2==L) break;
	}
	if(i==1000001 || L>R) return _P("0\n");
	ll lcm=A1*A2/__gcd(A1,A2);
	cout<<(R-L)/lcm+1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}