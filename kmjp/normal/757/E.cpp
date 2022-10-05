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

const int prime_max = 1100000;
int NP,prime[200000],divp[prime_max];
map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=i;j>=i&&j<prime_max;j+=i) divp[j]=i;
	}
}

int Q;
ll mo=1000000007;
int F[1<<20][21];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	F[0][0]=1;
	for(i=1;i<=19;i++) F[0][i]=2;
	FOR(i,1000000) {
		FOR(j,20) {
			F[i+1][j] = F[i][j];
			if(j) {
				F[i+1][j] += F[i+1][j-1];
				if(F[i+1][j]>=mo) F[i+1][j]-=mo;
			}
		}
	}
	scanf("%d",&Q);
	FOR(i,Q) {
		int R,N;
		scanf("%d%d",&R,&N);
		
		ll ret=1;
		while(N>1) {
			x=divp[N];
			y=0;
			while(N%x==0) {
				N/=x;
				y++;
			}
			ret = ret*F[R][y]%mo;
		}
		_P("%d\n",(int)ret);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}