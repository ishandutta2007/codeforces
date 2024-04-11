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
ll P[101];
ll K;
ll pro[1<<16];
ll num[1<<16];

vector<ll> A,B;
void dfs(ll v,int id,int mid, vector<ll>& V) {
	if(v>=1LL<<60) return;
	V.push_back(v);
	for(int i=id;i<mid;i++) if(v*P[i]/P[i]==v) dfs(v*P[i],i,mid,V);
}

ll hoge(ll v, ll k) {
	ll ret=0;
	FORR(a,A) {
		ret += lower_bound(ALL(B),v/a+1)-B.begin();
		if(ret>=k) return ret;
	}
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,16) {
		if(i<N) cin>>P[i];
		else P[i]=1LL<<60;
	}
	
	cin>>K;
	dfs(1,0,8,A);
	dfs(1,8,16,B);
	
	sort(ALL(A));
	sort(ALL(B));
	if(A.size()>B.size()) swap(A,B);
	
	ll ret=1LL<<60;
	for(i=59;i>=0;i--) if(hoge(ret-(1LL<<i),K)>=K) ret-=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}