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
int A[202020];
int del[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int p=1;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]==0) {
			del[i]=1;
		}
		else {
			if(A[i]<0) p=-p;
		}
	}
	if(p==-1) {
		x=-1;
		FOR(i,N) if(A[i]<0) {
			if(x==-1 || A[x]<A[i]) x=i;
		}
		del[x]=1;
	}
	x=-1,y=-1;
	FOR(i,N) {
		if(del[i]==0) {
			if(x>=0) cout<<1<<" "<<(x+1)<<" "<<(i+1)<<endl;
			x=i;
		}
		else {
			if(y>=0) cout<<1<<" "<<(y+1)<<" "<<(i+1)<<endl;
			y=i;
		}
	}
	if(x>=0 && y>=0) cout<<2<<" "<<(y+1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}