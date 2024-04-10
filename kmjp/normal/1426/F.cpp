#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,num;
string S;
ll A[4];
ll B[4][4];
ll C[4][4][4];
const ll mo=1000000007;
ll p3[202020];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	cin>>N>>S;
	
	p3[0]=1;
	FOR(i,N+1) p3[i+1]=p3[i]*3%mo;
	
	FORR(c,S) {
		if(c=='a') i=0;
		if(c=='b') i=1;
		if(c=='c') i=2;
		if(c=='?') i=3, num++;
		FOR(x,4) FOR(y,4) (C[x][y][i]+=B[x][y])%=mo;
		FOR(x,4) (B[x][i]+=A[x])%=mo;
		A[i]++;
	}
	
	ll ret=0;
	FOR(x,4) FOR(y,4) FOR(z,4) if(C[x][y][z]) {
		if(x==1||x==2) continue;
		if(y==0||y==2) continue;
		if(z==0||z==1) continue;
		i=(x==3)+(y==3)+(z==3);
		(ret+=C[x][y][z]*p3[num-i])%=mo;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}