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
int A[101];
map<int,int> M;
map<int,int> memo;

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

int hoge(int V) {
	if(V==0) return 0;
	if(memo.count(V)) return memo[V];
	int cnt[33]={};
	for(int i=0;(1<<i) <= V;i++) cnt[hoge((V&((1<<i)-1)) | (V>>(i+1)))]=1;
	
	int mex=0;
	while(cnt[mex]) mex++;
	return memo[V]=mex;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		auto m=enumpr(A[i]);
		FORR(r,m) M[r.first] |= 1<<(r.second-1);
	}
	
	int nim=0;
	FORR(r,M) nim ^= hoge(r.second);
	
	if(nim==0) cout<<"Arpa"<<endl;
	else cout<<"Mojtaba"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}