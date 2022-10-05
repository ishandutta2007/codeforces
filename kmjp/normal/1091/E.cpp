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
int A[502020];
int B[502020];
int M[502020];
int ret;

int hoge(int v) {
	int i;
	
	ll S=v;
	B[N]=v;
	FOR(i,N) B[i]=A[i], S+=A[i];
	
	sort(B,B+(N+1));
	reverse(B,B+(N+1));
	
	ll sum=0,mi=0;
	ZERO(M);
	for(int k=N+1;k>=1;k--) {
		mi+=M[k];
		sum-=1LL*M[k]*k;
		
		if(S>1LL*k*(k-1)+sum+mi*k) {
			if(B[k-1]<=v) return -1;
			else return 1;
		}
		
		S-=B[k-1];
		if(B[k-1]>=k) {
			mi++;
		}
		else {
			M[B[k-1]]++;
			sum+=B[k-1];
		}
		
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	int par=0;
	FOR(i,N) {
		scanf("%d",&A[i]);
		par ^= A[i]&1;
	}
	
	
	int L=N-((N%2)!=par);
	if(hoge(L)==1) return _P("-1\n");
	for(i=20;i>=1;i--) if(L>=(1<<i) && hoge(L-(1<<i))<=0) L-=1<<i;
	if(hoge(L)!=0) return _P("-1\n");
	int R=par;
	if(hoge(R)==-1) return _P("-1\n");
	for(i=20;i>=1;i--) if(R+(1<<i)<=N && hoge(R+(1<<i))>=0) R+=1<<i;
	if(hoge(R)!=0) return _P("-1\n");
	
	
	if(L<=R) {
		for(i=L;i<=R;i+=2) _P("%d ",i);
	}
	else {
		_P("-1\n");
	}
	
	
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}