#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X;
const int prime_max = 100000;
vector<int> prime;
int NP,divp[prime_max];
int alive[101010];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int opA(ll v) {
	int i,num=0;
	cout<<"A "<<v<<endl;
	if(X) {
		for(i=v;i<=N;i+=v) num+=alive[i];
	}
	else {
		cin>>num;
	}
	return num;
}

int opB(ll v) {
	int i,num=0;
	cout<<"B "<<v<<endl;
	if(X) {
		for(i=v;i<=N;i+=v) {
			num+=alive[i];
			if(i!=X) alive[i]=0;
		}
	}
	else {
		cin>>num;
	}
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) alive[i]=1;
	cprime();
	
	ll cur=1;
	vector<int> cand;
	int did=0;
	FOR(i,NP) {
		
		if(prime[i]>N) {
			break;
		}
		if(1LL*prime[i]*prime[i]>N) {
			cand.push_back(prime[i]);
			continue;
		}
		
		did++;
		opB(prime[i]);
		while(cur*prime[i]<=N) {
			x=opA(cur*prime[i]);
			if(x==0) break;
			cur*=prime[i];
		}
	}
	
	
	while(cand.size()) {
		int step=min(100,(int)cand.size());
		int num=opA(1);
		FOR(i,step) {
			num-=opB(cand[cand.size()-1-i]);
		}
		int num2=opA(1);
		if(num2!=num) {
			FOR(i,step) if(opA(cand[cand.size()-1-i])) cur*=cand[cand.size()-1-i];
		}
		cand.resize(cand.size()-step);
		
	}
	
	cout<<"C "<<cur<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}