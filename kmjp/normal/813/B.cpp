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

ll X,Y,L,R;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>L>>R;
	vector<ll> NG;
	
	ll a=1,b=1;
	FOR(x,62) {
		b=1;
		if(a>R) break;
		FOR(y,62) {
			if(b>R) break;
			if(L<=a+b && a+b<=R) NG.push_back(a+b);
			
			if(b*Y/Y!=b) break;
			b*=Y;
		}
		if(a*X/X!=a) break;
		a*=X;
	}
	NG.push_back(L-1);
	NG.push_back(R+1);
	sort(ALL(NG));
	ll ma=0;
	FOR(i,NG.size()-1) ma=max(ma,NG[i+1]-NG[i]-1);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}