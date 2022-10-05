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

const int prime_max = 2100000;
int NP,prime[200000],divp[prime_max];
map<int,int> fp[2020202];
int add;
void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		divp[i]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int N;
int P[202020],step[202020];
map<int,int> C[2020202];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	for(i=2;i<=2000000;i++) {
		x=i;
		while(x>1) {
			fp[i][divp[x]]++;
			x/=divp[x];
		}
	}
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	sort(P,P+N);
	reverse(P,P+N);
	
	FOR(i,N) {
		if(C[P[i]].empty()) {
			C[P[i]][1]=1;
		}
		else {
			step[i]=1;
			P[i]--;
			FORR(f,fp[P[i]]) C[f.first][f.second]++;
		}
	}
	FOR(i,N) {
		if(step[i]==0) {
			if(C[P[i]][1]>1 || C[P[i]].rbegin()->first>1) {
				C[P[i]][1]--;
				if(--C[P[i]][1]==0) C[P[i]].erase(1);
				step[i]=2;
				assert(1);
			}
		}
		else {
			int rem=0;
			FORR(f,fp[P[i]]) {
				if(C[f.first][f.second]==1 && C[f.first].rbegin()->first==f.second) rem=1;
			}
			if(rem==0) {
				FORR(f,fp[P[i]]) {
					if(--C[f.first][f.second]==0) C[f.first].erase(f.second);
				}
				add=1;
			}
		}
	}
	
	ll ret=1;
	for(i=1;i<=2000000;i++) if(C[i].size()) {
		FOR(x,C[i].rbegin()->first) ret=ret*i%mo;
	}
	
	cout<<(ret+add)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}