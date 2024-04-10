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

ll N,K;
ll ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll mi=K*(K+1)/2;
	if(N<mi) return _P("NO\n");
	if(K==2 && N==4) return _P("NO\n");
	if(K==3 && N==8) return _P("NO\n");
	
	ll A=0;
	for(i=30;i>=0;i--) {
		ll B=A+(1<<i);
		ll C=(B+B+K-1)*K/2;
		if(C<=N) A=B;
	}
	
	ll sum=0;
	FOR(i,K) {
		ret[i]=A+i;
		sum+=ret[i];
	}
	for(i=K-1;i>=0;i--) {
		if(sum<N) {
			int add=min(2*ret[i-1]-ret[i],N-sum);
			ret[i]+=add;
			sum+=add;
		}
	}
	cout<<"YES"<<endl;
	FOR(i,K) cout<<ret[i]<<" ";
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}