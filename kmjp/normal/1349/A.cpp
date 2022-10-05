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
int A[202020];

const int prime_max = 200000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>N;
	FOR(i,N) {
		cin>>x;
		A[x]++;
	}
	
	ll ret=1;
	FORR(p,prime) {
		vector<int> V;
		int sum=0;
		for(x=p;x<=200000;x+=p) if(A[x]) {
			y=x;
			r=0;
			while(y%p==0) y/=p, r++;
			
			FOR(j,A[x]) {
				V.push_back(r);
			}
			sum+=A[x];
		}
		if(N-sum>=2) continue;
		FOR(i,min(2,N-sum)) V.push_back(0);
		sort(ALL(V));
		int mi=max(V[0],V[1]);
		FOR(j,mi) ret*=p;
		
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}