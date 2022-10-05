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

ll A[28];
ll B[28];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,14) cin>>A[i];
	ll ma=0;
	FOR(i,14) {
		FOR(j,14) B[j]=A[(j+i)%14];
		ll left=B[13];
		B[13]=0;
		FOR(j,14) B[j]+=left/14;
		FOR(j,left%14) B[j]++;
		ll tot=0;
		FOR(j,14) if(B[j]%2==0) tot+=B[j];
		ma=max(ma,tot);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}