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

const int prime_max = 3000000;
vector<int> prime;
int NP,divp[prime_max],re[3000000];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		re[i]=NP+1;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j<prime_max;j+=i) if(divp[j]==0) divp[j]=max(divp[j],(int)(j/i));
	}
}

int N;
int A[404040];
map<int,int> M;
vector<int> R;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) {
		cin>>x;
		M[x]++;
	}
	cprime();
	
	
	while(M.size()) {
		x=M.rbegin()->first;
		y=M.rbegin()->second;
		if(re[x]==0) {
			j=divp[x];
		}
		else {
			j=re[x];
			swap(x,j);
		}
		
		FOR(i,y) R.push_back(x);
		M[x]-=y;
		M[j]-=y;
		if(M[x]==0) M.erase(x);
		if(M[j]==0) M.erase(j);
	}
	FORR(r,R) cout<<r<<" ";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}