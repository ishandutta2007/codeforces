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
int A[505050];
int C[7];
int D[50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	D[4]=0;
	D[8]=1;
	D[15]=2;
	D[16]=3;
	D[23]=4;
	D[42]=5;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		x=D[x];
		
		if(x==0) C[0]++;
		else if(C[x-1]) {
			C[x-1]--;
			C[x]++;
		}
	}
	
	cout<<N-C[5]*6<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}