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
int nex[202020];
unordered_map<ll,int> NN;
const int DI=150;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FORR(c,S) c-='0';
	nex[N]=N+1;
	for(i=N-1;i>=0;i--) {
		nex[i]=nex[i+1];
		if(S[i]) nex[i]=i+1;
	}
	ll ret=0;
	int num=0;
	FOR(i,N) {
		if(S[i]==0) num=0;
		else num++;
		ret+=num;
	}
	for(l=2;l<=DI;l++) {
		ll cur=0;
		NN.clear();
		NN[0]++;
		FOR(i,N) {
			if(S[i]) cur+=l-1;
			else cur--;
			ret+=NN[cur];
			NN[cur]++;
		}
	}
	FOR(i,N) {
		int cur=i;
		for(j=1;j<=202000/DI+3;j++) {
			int ne=max(nex[cur],i+j*(DI+1));
			if(ne>N) break;
			int nene=min(N,nex[nex[cur]]-1);
			if(nene>=ne) {
				ne--;
				ret+=(nene-i)/j-(ne-i)/j;
			}
			cur=nex[cur];
			
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}