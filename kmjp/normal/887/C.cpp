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

int A[24];

void ok() {
	int i,j;
	FOR(i,6) {
		FOR(j,4) {
			if(A[1+i*4]!=A[1+i*4+j]) return;
		}
	}
	cout<<"YES"<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,24) cin>>A[1+i];
	
	FOR(i,4) {
		swap(A[2],A[6]);
		swap(A[6],A[10]);
		swap(A[10],A[23]);
		swap(A[4],A[8]);
		swap(A[8],A[12]);
		swap(A[12],A[21]);
		
		if(i==0||i==2) ok();
	}
	FOR(i,4) {
		swap(A[13],A[5]);
		swap(A[5],A[17]);
		swap(A[17],A[21]);
		swap(A[14],A[6]);
		swap(A[6],A[18]);
		swap(A[18],A[22]);
		
		if(i==0||i==2) ok();
	}
	FOR(i,4) {
		swap(A[3],A[16]);
		swap(A[16],A[10]);
		swap(A[10],A[17]);
		swap(A[4],A[14]);
		swap(A[14],A[9]);
		swap(A[9],A[19]);
		
		if(i==0||i==2) ok();
	}
	
	cout<<"NO"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}