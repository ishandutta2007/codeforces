#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
ll A,B;

const int prime_max = 5200000;
int NP,prime[1100000],divp[prime_max];
ll num[5050500];
ll sum[5050500];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		for(int j=i*2;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	for(i=2;i<=5000000;i++) {
		if(divp[i]==0) num[i]=1;
		else num[i]=num[i/divp[i]]+1;
		sum[i] = sum[i-1]+num[i];
	}
	
	cin>>T;
	while(T--) {
		cin>>A>>B;
		_P("%d\n",(int)(sum[A]-sum[B]));
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}