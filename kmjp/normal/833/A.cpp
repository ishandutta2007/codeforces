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
int A,B;

const int prime_max = 35000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d%d",&A,&B);
		
		ll X=A,Y=B;
		
		if(X*X%Y!=0 || Y*Y%X!=0) {
			_P("NO\n");
			continue;
		}
		X*=Y;
		
		ll a=0;
		for(j=20;j>=0;j--) {
			ll b=a+(1LL<<j);
			if(b*b*b<=X) a=b;
		}
		if(a*a*a==X) {
			_P("YES\n");
		}
		else {
			_P("NO\n");
		}

		
		/*
		FOR(j,NP) {
			y=prime[j];
			int a=0,b=0;
			while(A%y==0) a++,A/=y;
			if(a==0) continue;
			while(B%y==0) b++,B/=y;
			if(b==0) continue;
			
			if((a+b)%3!=0) break;
			x=(a+b)/3;
			if(a<x || b<x) break;
		}
		if(j==NP && A==1 && B==1) _P("YES\n");
		else _P("NO\n");
		*/
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}