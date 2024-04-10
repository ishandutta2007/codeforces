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


int T;
int N,K;
int A[501][501];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(y,N) FOR(x,N) A[y][x]=0;
		int R[501]={},C[501]={};
		FOR(y,N) FOR(x,N) if(K) {
			K--;
			A[(y+x)%N][x]=1;
			R[(y+x)%N]++;
			C[x]++;
		}
		x=*max_element(R,R+N)-*min_element(R,R+N);
		y=*max_element(C,C+N)-*min_element(C,C+N);
		int ret=x*x+y*y;
		cout<<ret<<endl;
		FOR(y,N) {
			FOR(x,N) cout<<A[y][x];
			cout<<endl;
		}
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}