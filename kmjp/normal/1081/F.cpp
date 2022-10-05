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

int N,T;

int ask(int L,int R) {
	int x;
	cout<<"? "<<L<<" "<<R<<endl;
	cout.flush();
	cin>>x;
	return x;
}

int A[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	
	int did=0;
	for(i=1;i<N;i++) {
		x=-1;
		FOR(j,15) {
			y=ask(i+1,N);
			y=ask(i+1,N);
			if(y!=T) {
				x=y;
				break;
			}
		}
		
		if(x==-1) {
			if(did+1==i/2) A[i]=1, did++;
		}
		else {
			if(x==(i-(did+1))+(T-(did+1))) A[i]=1, did++;
		}
		
		while(y!=T) {
			y=ask(i+1,N);
			y=ask(i+1,N);
		}
		
	}
	
	if(did<T) A[N]=1, did++;
	
	cout<<"! ";
	FOR(i,N) cout<<A[i+1];
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}