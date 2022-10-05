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

int T,N;
string S;

int C[1<<18][27];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		char tar='a';
		x=N;
		while(x>1) tar++,x/=2;
		FOR(i,N) {
			FOR(j,27) C[i][j]=0;
			C[i][S[i]-'a']++;
			if(S[i]!=tar) C[i][26]=1;
		}
		
		
		while(N>1) {
			tar--;
			for(i=0;i<N;i+=2) {
				int c=S.size()/N;
				x=C[i][26]+c-C[i+1][tar-'a'];
				y=C[i+1][26]+c-C[i][tar-'a'];
				
				C[i/2][26]=min(x,y);
				FOR(j,26) C[i/2][j]=C[i][j]+C[i+1][j];
			}
			N/=2;
		}
		cout<<C[0][26]<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}