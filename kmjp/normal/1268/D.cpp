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
string S[2020];
string T[2020];
int deg[2020];

int scc() {
	int D[2020];
	int i;
	FOR(i,N) D[i]=deg[i];
	sort(D,D+N);
	int sum=0;
	FOR(i,N-1) {
		sum+=D[i]-i;
		if(sum==0) return 0;
	}
	return 1;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		FOR(j,N) deg[i]+=S[i][j]-'0';
	}
	
	if(scc()) {
		cout<<0<<" "<<1<<endl;
		return;
	}
	
	int ret=0;
	FOR(i,N) {
		FOR(j,N) if(i!=j) {
			if(S[i][j]=='1') deg[i]--, deg[j]++;
			else deg[i]++, deg[j]--;
		}
		if(scc()) {
			ret++;
		}
		FOR(j,N) if(i!=j) {
			if(S[i][j]=='0') deg[i]--, deg[j]++;
			else deg[i]++, deg[j]--;
		}
	}
	
	if(ret) {
		cout<<1<<" "<<ret<<endl;
		return;
	}
	
	if(N==4) {
		cout<<-1<<endl;
	}
	else if(N==6) {
		cout<<2<<" "<<18<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}