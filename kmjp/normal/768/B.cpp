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

ll N,L,R;
map<ll,ll> len;

ll getlen(ll N) {
	if(N==0) return 0;
	if(len.count(N)==0) {
		len[N]=1+getlen(N/2)*2;
	}
	return len[N];
}

int go(ll N,ll M) {
	
	ll v = getlen(N)/2+1;
	if(M==v) return N%2;
	else if(M<v) return go(N/2,M);
	else return go(N/2,M-v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	
	
	ll ret=0;
	for(ll a=L;a<=R;a++) ret+=go(N,a);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}