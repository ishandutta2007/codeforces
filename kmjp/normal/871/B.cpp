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
int P[5050];
int B[5050];
int BX[5050];
int PX[5050];

int TN;
int TP[5050]={1,0,3,2};
int TB[5050];

int ask(int p,int b) {
	int ret;
	if(TN) {
		cout<<p<<" "<<b<<" "<<(TP[p]^TB[b])<<endl;
		return TP[p]^TB[b];
	}
	
	cout<<"? "<<p<<" "<<b<<endl;
	cin>>ret;
	return ret;
}

void answer(int ret) {
	int i;
	cout<<"!"<<endl;
	cout<<ret<<endl;
	FOR(i,N) {
		cout<<P[i];
		if(i!=N-1) cout<<" ";
	}
	cout<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	if(TN) {
		N=TN;
		FOR(i,N) TB[TP[i]]=i;
	}
	else {
		cin>>N;
	}
	FOR(i,N) BX[i]=ask(0,i);
	FOR(i,N) PX[i]=ask(i,i);
	
	int ret=0;
	FOR(i,N) {
		int cnt[5050]={};
		int P2[5050];
		
		//P[0]=i
		FOR(j,N) B[j]=BX[j]^i, cnt[B[j]]++;
		FOR(j,N) if(cnt[j]!=1) break;
		if(j<N) continue;
		FOR(j,N) P2[B[j]]=j;
		if(P2[0]!=i) continue;
		FOR(j,N) if(PX[j]!=(P2[j]^B[j])) break;
		if(j<N) continue;
		ret++;
		FOR(j,N) P[j]=P2[j];
		
	}
	
	answer(ret);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}