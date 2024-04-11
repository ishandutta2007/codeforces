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

int N,X,Y;
int A[505050];

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;
vector<pair<int,int>> V;
void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

ll SN[2010101];
ll ST[2010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	scanf("%d%d%d",&N,&X,&Y);
	FOR(i,N) {
		scanf("%d",&A[i]);
		SN[A[i]]++;
		ST[A[i]]+=A[i];
	}
	for(i=1;i<=2010000;i++) {
		SN[i]+=SN[i-1];
		ST[i]+=ST[i-1];
	}
	
	ll mi=1LL*X*N;
	FOR(i,NP) {
		x=prime[i];
		int les=min(x-1,X/Y);
		
		ll tot=0;
		for(j=x;;j+=x) {
			tot += ((SN[j]-SN[j-(1+les)])*j-(ST[j]-ST[j-(1+les)]))*Y;
			tot += (SN[j-(1+les)]-SN[j-x])*X;
			if(j>1000000) break;
		}
		mi=min(mi,tot);
	}
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}