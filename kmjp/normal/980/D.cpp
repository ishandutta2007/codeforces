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
int A[5050];
int num[5050];
int pre[5050];

const int prime_max = 10000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]) {
			for(x=0;prime[x]*prime[x]<=abs(A[i]) && x<NP;x++) {
				while(abs(A[i])%(prime[x]*prime[x])==0) A[i]/=(prime[x]*prime[x]);
			}
		}
		for(y=i-1;y>=0;y--) if(A[i]==A[y]) break;
		pre[i]=y;
		
	}
	FOR(x,N) {
		int hoge=0;
		for(y=x;y<N;y++) {
			if(A[y] && pre[y]<x) hoge++;
			
			num[max(1,hoge)]++;
		}
	}
	for(i=1;i<=N;i++) cout<<num[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}