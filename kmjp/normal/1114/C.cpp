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

ll N,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>B;
	map<ll,int> M;
	for(i=2;1LL*i*i<=B;i++) {
		while(B%i==0) {
			B/=i;
			M[i]++;
		}
	}
	if(B>1) M[B]++;
	
	ll num=1LL<<60;
	
	FORR(m,M) {
		ll tot=0;
		ll C=N;
		while(C) {
			tot+=C/m.first;
			C/=m.first;
		}
		num=min(num,tot/m.second);
	}
	
	cout<<num<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}