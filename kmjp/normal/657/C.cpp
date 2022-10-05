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

ll N,K,B,C;
int T[202020];
multiset<ll> S[5];
ll sum[5];
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>B>>C;
	FOR(i,N) cin>>T[i], T[i]+=1<<30;
	sort(T,T+N);
	
	B=min(B,C*5);
	ll L=2111111115;
	ret=1LL<<60;
	
	FOR(j,N) {
		r=T[j];
		FOR(i,5) {
			ll d=L+i-r;
			ll sc=(d/5)*B+(d%5)*C;
			S[i].insert(-sc);
			sum[i]+=sc;
			if(S[i].size()>K) sum[i]+=*S[i].begin(),S[i].erase(S[i].begin());
		}
		FOR(i,5) {
			int cont=r+i;
			if(S[cont%5].size()>=K) ret=min(ret,sum[cont%5]-((L+cont%5)-cont)/5*K*B);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}