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
string S;
int L[101010],R[101010];
int T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int ma=0;
	for(i=1;i<=N;i++) {
		if(S[i-1]=='G') {
			T++;
			L[i]=L[i-1]+1;
			ma=max(ma,L[i]);
		}
	}
	for(i=N;i>=1;i--) {
		if(S[i-1]=='G') {
			R[i]=R[i+1]+1;
			ma=max(ma,R[i]);
		}
		if(R[i+1]+L[i-1]<T) ma=max(ma,R[i+1]+L[i-1]+1);
		if(R[i+1]+L[i-1]==T) ma=max(ma,T);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}