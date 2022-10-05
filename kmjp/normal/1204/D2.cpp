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

int dpo[101010][2];
int dpp[101010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	for(i=N-1;i>=0;i--) {
		S[i]-='0';
		if(S[i]==1) {
			dpo[i][0]=max(dpo[i+1][0],dpo[i+1][1]);
			dpo[i][1]=1+dpo[i+1][1];
		}
		else {
			dpo[i][0]=1+max(dpo[i+1][0],dpo[i+1][1]);
			dpo[i][1]=dpo[i+1][1];
		}
		if(S[i]) {
			if(1+max(dpp[i+1][0],dpp[i+1][1])==max(1+dpo[i+1][1],dpo[i+1][0])) {
				S[i]=0;
			}
		}
		if(S[i]==1) {
			dpp[i][0]=max(dpp[i+1][0],dpp[i+1][1]);
			dpp[i][1]=1+dpo[i+1][1];
		}
		else {
			dpp[i][0]=1+max(dpp[i+1][0],dpp[i+1][1]);
			dpp[i][1]=dpp[i+1][1];
		}
	}
	
	
	FOR(i,N) cout<<(int)S[i];
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}