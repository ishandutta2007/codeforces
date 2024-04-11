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
int A[101010];
int B[101010];
string S;

int Rma=1000000000,Rmi=-1000000000;
int Lma=1000000000,Lmi=-1000000000;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>S;
	FOR(i,N) B[i]=S[i]=='1';
	
	for(i=4;i<N;i++) {
		if(B[i-1]*B[i-2]*B[i-3]*B[i-4]==1) {
			if(B[i]==0) {
				Rma=min({Rma,A[i]-1,A[i-1]-1,A[i-2]-1,A[i-3]-1,A[i-4]-1});
			}
			else {
				Rmi=max(Rmi,min({A[i],A[i-1],A[i-2],A[i-3],A[i-4]}));
			}
		}
		if(B[i-1]+B[i-2]+B[i-3]+B[i-4]==0) {
			if(B[i]==1) {
				Lmi=max({Lmi,A[i]+1,A[i-1]+1,A[i-2]+1,A[i-3]+1,A[i-4]+1});
			}
			else {
				Lma=min(Lma,max({A[i],A[i-1],A[i-2],A[i-3],A[i-4]}));
			}
		}
	}
	
	cout<<Lmi<<" "<<Rma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}