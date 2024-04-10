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
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	NP++;
	prime.push_back(1);
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		for(ll j=i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=NP;
		prime.push_back(i); NP++;
	}
}

int N;
int id;
vector<int> C[101010];
int mi=2020202;

set<int> S[1010101];
queue<int> Q;

int D[90000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cprime();
	cin>>N;
	int mi=10101010;
	
	FOR(i,N) {
		cin>>r;
		vector<int> V;
		V.push_back(0);
		while(r>1) {
			x=divp[r];
			if(V.size() && V.back()==x) V.pop_back();
			else V.push_back(x);
			r/=prime[x];
		}
		if(V.size()==1) return _P("1\n");
		if(V.size()==2) {
			x=V[0];
			y=V[1];
		}
		else {
			x=V[1];
			y=V[2];
		}
		if(S[x].count(y)) mi=2;
		C[x].push_back(y);
		C[y].push_back(x);
		S[x].insert(y);
	}
	
	if(mi<=2) return _P("%d\n",mi);
	FOR(i,NP) if(prime[i]>1 && prime[i]<=1000) {
		FOR(j,NP) D[j]=1010101;
		D[i]=0;
		
		Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,C[x]) {
				if(D[e]>=D[x]) mi=min(mi,D[x]+D[e]+1);
				if(D[e]>D[x]+1) {
					D[e]=D[x]+1;
					Q.push(e);
				}
			}
		}
	}
	if(mi>N) mi=-1;
	cout<<mi<<endl;
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}