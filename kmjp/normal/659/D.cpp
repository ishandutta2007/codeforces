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

int N;
int X[1010],Y[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+1) cin>>X[i]>>Y[i];
	FOR(i,N+1) X[N-i]-=X[0],Y[N-i]-=Y[0];
	
	int ret=0;
	if(X[N-1]>0) { //clockwise
		for(i=1;i<N;i++) {
			if(X[i]-X[i-1]>0&&Y[i+1]>Y[i]) ret++;
			if(X[i]-X[i-1]<0&&Y[i+1]<Y[i]) ret++;
			if(Y[i]-Y[i-1]>0&&X[i+1]<X[i]) ret++;
			if(Y[i]-Y[i-1]<0&&X[i+1]>X[i]) ret++;
		}
	}
	else { //c-clockwise
		for(i=1;i<N;i++) {
			if(X[i]-X[i-1]>0&&Y[i+1]<Y[i]) ret++;
			if(X[i]-X[i-1]<0&&Y[i+1]>Y[i]) ret++;
			if(Y[i]-Y[i-1]>0&&X[i+1]>X[i]) ret++;
			if(Y[i]-Y[i-1]<0&&X[i+1]<X[i]) ret++;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}