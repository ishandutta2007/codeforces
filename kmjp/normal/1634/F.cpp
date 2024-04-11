#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,Q;
int A[303030],B[303030],C[303030],D[303030],F[303030];
int mo;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&Q,&mo);
	FOR(i,N) scanf("%d",&A[i+1]);
	int NZ=0;
	FOR(i,N) {
		scanf("%d",&B[i+1]);
		C[i+1]=A[i+1]+mo-B[i+1];
		if(C[i+1]>=mo) C[i+1]-=mo;
		D[i+1]=C[i+1];
		if(i) D[i+1]-=C[i];
		if(i-1) (D[i+1]-=C[i-1]);
		while(D[i+1]<0) D[i+1]+=mo;
		if(D[i+1]==0) NZ++;
	}
	
	F[1]=1%mo;
	for(i=2;i<=N+3;i++) {
		F[i]=(F[i-1]+F[i-2]);
		if(F[i]>=mo) F[i]-=mo;
	}
	
	
	while(Q--) {
		char buf[10];
		scanf("%s%d%d",buf,&x,&y);
		if(D[x]==0) NZ--;
		if(y+1<=N && D[y+1]==0) NZ--;
		if(y+2<=N && D[y+2]==0) NZ--;
		if(buf[0]=='A') {
			D[x]+=1;
			D[y+1]+=mo-F[y+1-(x-1)];
			D[y+2]+=mo-F[y+0-(x-1)];
		}
		else {
			D[x]+=mo-1;
			D[y+1]+=F[y+1-(x-1)];
			D[y+2]+=F[y+0-(x-1)];
		}
		if(D[x]>=mo) D[x]-=mo;
		if(D[y+1]>=mo) D[y+1]-=mo;
		if(D[y+2]>=mo) D[y+2]-=mo;
		
		
		if(D[x]==0) NZ++;
		if(y+1<=N && D[y+1]==0) NZ++;
		if(y+2<=N && D[y+2]==0) NZ++;
		
		if(NZ==N) {
			_P("YES\n");
		}
		else {
			_P("NO\n");
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}