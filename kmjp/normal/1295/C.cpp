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

int Q;
string S,T;
int nex[202020][26];
int N;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>S>>T;
		N=S.size();
		S+=S;
		FOR(i,26) nex[2*N][i]=1<<30;
		for(i=2*N-1;i>=0;i--) {
			FOR(j,26) nex[i][j]=nex[i+1][j];
			nex[i][S[i]-'a']=i+1;
		}
		
		ll cur=0;
		FORR(c,T) {
			if(nex[cur%N][c-'a']==1<<30) {
				cout<<-1<<endl;
				cur=-1;
				break;
			}
			cur+=nex[cur%N][c-'a']-cur%N;
		}
		if(cur>=0) cout<<(cur+N-1)/N<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}