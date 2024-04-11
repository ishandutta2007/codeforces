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
ll A[2020];
vector<ll> cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		for(x=1;x<=min(A[i],100000LL);x++) {
			if(A[i]/x>=100000) cand.push_back((A[i]-1)/x);
		}
	}
	
	for(x=1;x<=100000;x++) cand.push_back(x);
	
	cand.push_back(1LL<<40);
	cand.push_back(1LL<<41);
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	ll ma=1;
	FOR(i,cand.size()-1) {
		ll pre=cand[i-1];
		ll now=cand[i];
		
		ll num=0,sum=0;
		FOR(x,N) {
			num+=(A[x]+now-1)/now;
			sum+=(A[x]+now-1)/now*now-A[x];
		}
		
		if(sum<=K) ma=now;
		else {
			ll del=sum-K;
			ll hoge=now-(del+(num-1))/num;
			if(hoge>pre) ma=hoge;
		}
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}