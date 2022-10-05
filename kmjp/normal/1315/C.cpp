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
int N;
int B[202];
int D[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(B);
		ZERO(D);
		FOR(i,N) {
			cin>>B[2*i];
			D[B[2*i]]=1;
		}
		for(i=1;i<=2*N;i++) if(D[i]==0) {
			for(j=0;j<2*N;j+=2) if(B[j+1]==0 && B[j]<i) {
				B[j+1]=i;
				break;
			}
			if(j==2*N) break;
		}
		
		if(i<=2*N) {
			cout<<-1<<endl;
		}
		else {
			FOR(i,2*N) cout<<B[i]<<" ";
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