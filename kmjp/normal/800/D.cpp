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
ll A[1010101],B[1010101],C[1010101],G[1010101];
ll p2[1010101];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	p2[0]=1;
	FOR(i,1010000) p2[i+1]=p2[i]*2%mo;
	
	FOR(i,N) {
		cin>>x;
		A[x]++;
		(C[x]+=1LL*x*x + B[x]*x)%=mo;
		(B[x]+=x)%=mo;
	}
	
	for(i=1;i<1000000;i*=10) {
		for(j=999999;j>=0;j--) if((j/i)%10!=9) {
			(A[j]+=A[i+j])%=mo;
			(C[j]+=C[i+j]+B[j]*B[i+j])%=mo;
			(B[j]+=B[i+j])%=mo;
		}
	}
	FOR(i,1000000) if(A[i]) G[i]=p2[A[i]-1]*C[i]%mo;
	for(i=1;i<1000000;i*=10) {
		FOR(j,1000000) if((j/i)%10!=9) {
			G[j]=(G[j]+mo-G[i+j])%mo;
		}
	}
	
	ll ret=0;
	FOR(i,1000000) ret ^= i*G[i];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}