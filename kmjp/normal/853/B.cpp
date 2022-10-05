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

int N,M,K;
int D[101010],F[101010],T[101010],C[101010];

vector<int> I[1010101],O[1010101];

ll S[2010101];
ll pre[101010];
ll L[1010101],R[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&K);
	FOR(i,M) {
		scanf("%d%d%d%d",&D[i],&F[i],&T[i],&C[i]);
		
		if(F[i]>0) I[D[i]].push_back(i);
		if(T[i]>0) O[D[i]].push_back(i);
	}
	ll sum=0;
	FOR(i,N) pre[i+1]=1LL<<40, sum+=pre[i+1];
	FOR(i,1010000) {
		FORR(e,I[i]) if(C[e]<pre[F[e]]) {
			sum -= pre[F[e]]-C[e];
			pre[F[e]]=C[e];
		}
		L[i]=sum;
	}
	sum=0;
	FOR(i,N) pre[i+1]=1LL<<40, sum+=pre[i+1];
	for(i=1010000;i>=0;i--) {
		FORR(e,O[i]) if(C[e]<pre[T[e]]) {
			sum -= pre[T[e]]-C[e];
			pre[T[e]]=C[e];
		}
		R[i]=sum;
	}
	ll mi=1LL<<40;
	for(i=1;i+K<=1000001;i++) mi=min(mi,L[i-1]+R[i+K]);
	if(mi>=1LL<<40) mi=-1;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}