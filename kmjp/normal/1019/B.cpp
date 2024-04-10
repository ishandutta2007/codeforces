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
int V[101010];
int tar;
int A[]={1,2,1,2,3,4,3,2};
int ask(int v) {
	int R;
	v=(v+2*N)%N;
	if(V[v]==1<<30) {
		cout<<"? "<<v+1<<endl;
		fflush(stdout);
		cin>>V[v];
		//V[v]=A[v];
		
	}
	
	return V[v];
}

void ans(int v) {
	v=(v+2*N)%N;
	cout<<"! "<<(min(v,(v+N/2)%N)+1)<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N%4) return _P("! -1\n");
	FOR(i,N) V[i]=1<<30;
	
	x=ask(0);
	y=ask(N/2);
	if(x==y) ans(0);
	
	int L=1,R=N/2;
	while(R>L+1) {
		int M=(L+R)/2;
		i=ask(M);
		j=ask(M+N/2);
		
		if(i==j) ans(M);
		if((x<y) == (i<j)) L=M;
		else R=M;
	}
	ans(L);
}


int main(int argc,char** argv){
	solve(); return 0;
}