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

int N,A,B;
int X[201],Y[201];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,N) {
		cin>>X[i*2]>>Y[i*2];
		X[i*2+1]=Y[i*2];
		Y[i*2+1]=X[i*2];
	}
	int ma=0;
	FOR(i,2*N) for(j=(i+2)/2*2;j<2*N;j++) {
		if(X[i]+X[j]<=A && max(Y[i],Y[j])<=B) ma=max(ma,X[i]*Y[i]+X[j]*Y[j]);
		if(Y[i]+Y[j]<=B && max(X[i],X[j])<=A) ma=max(ma,X[i]*Y[i]+X[j]*Y[j]);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}