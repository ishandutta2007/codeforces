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

int P,Q;

const int prime_max = 2000001;
int NP,prime[300000],divp[prime_max];
map<int,int> M;

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

int ispar(int num) {
	int d[10]={};
	int n=0,i;
	while(num) {
		d[n]=num%10;
		num/=10;
		n++;
	}
	FOR(i,n) if(d[i]!=d[n-1-i]) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>P>>Q;
	
	cprime();
	divp[1]=1;
	int ma=-1;
	ll pi=0,ru=0;
	for(i=1;i<=2000000;i++) {
		if(divp[i]==0) pi++;
		if(ispar(i)) ru++;
		if(pi*Q<=P*ru) ma=i;
	}
	if(ma==-1) cout<<"Palindromic tree is better than splay tree"<<endl;
	else cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}