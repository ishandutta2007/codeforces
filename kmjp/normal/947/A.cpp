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
int NP,prime[100000],divp[prime_max];
map<int,int> M;
int X;
int ret=1010101;
void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=2*i;j>=i&&j<prime_max;j+=i) divp[j]=max(divp[j],i);
	}
}

int hoge(int X) {
	int i;
	int ma=0;
	
	if(divp[X]==0) return ret;
	return X-divp[X]+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>X;
	
	int ma=0;
	FOR(i,NP) if(X%prime[i]==0) ma=prime[i];
	
	for(i=X-ma+1;i<=X;i++) ret=min(ret,hoge(i));
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}