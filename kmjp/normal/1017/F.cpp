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

unsigned int  N,A,B,C,D;
unsigned int ret=0;

const int prime_max = 0x10000;
int NP,prime[100000],divp[prime_max];
int NG[0x10000];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

unsigned int  F(unsigned int  x) {
	return (((A*x+B)*x+C)*x+D);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C>>D;
	
	cprime();
	FOR(i,NP) {
		j=prime[i];
		for(x=j*2;x<0x10000;x+=j) NG[x]=1;
	}
	
	for(i=2;i<=N;i++) {
		if((i&0xFFFF)==0) {
			ZERO(NG);
			FOR(y,NP) {
				j=prime[y];
				for(x=(i+j-1)/j*j;x<i+0x10000;x+=j) NG[x&0xFFFF]=1;
			}
		}
		if(NG[i&0xFFFF]==0) {
			unsigned int num=N;
			unsigned int R=F(i);
			unsigned int pat=0;
			while(num>=i) pat+=num/i, num/=i;
			ret+=R*pat;
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}