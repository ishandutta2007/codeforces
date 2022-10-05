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

ll N,H;

ll hoge(ll H,ll MH) {
	if(MH<=H) return MH*(MH+1)/2;
	if((MH+H)%2==0) {
		ll a=(MH+H)/2;
		return a*(a+1)/2 + (H+(a-1))*(a-H)/2;
	}
	else {
		ll a=(MH+H)/2;
		return a*(a+1)/2 + (H+a)*(a+1-H)/2;
	}
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	
	ll MH=1LL<<31;
	for(i=30;i>=0;i--) {
		if(hoge(H,MH-(1LL<<i))>=N) MH-=1LL<<i;
	}
	cout<<MH<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}