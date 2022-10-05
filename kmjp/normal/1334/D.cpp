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


int T;
int N;
ll L,R;
ll S[101010];
ll V[101010];

vector<ll> VV={1,2,1,3,2,3,1};

int hoge(ll N,ll a) {
	if(N<=3) return VV[a-1];
	if(a<=(N-1)*2) {
		if(a%2==1) return 1;
		return a/2+1;
	}
	if(a==1LL*N*(N-1)+1) return 1;
	
	a-=(N-1)*2;
	int x=lower_bound(S,S+101001,a+S[101001-(N-1)])-S;
	a=a+S[101001-(N-1)]-(S[x-1]+1);
	if(a%2==0) return N-(101001-x);
	return N+a/2-(101001-x)+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=101000;i++) {
		V[i]=(101001-i)*2;
		S[i]=S[i-1]+V[i];
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>L>>R;
		
		for(ll a=L;a<=R;a++) cout<<hoge(N,a)<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}