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
string S;
ll fact[20];

set<vector<int>> V;
vector<int> ma;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	fact[0]=1;
	for(i=1;i<=19;i++) {
		fact[i]=fact[i-1]*i;
	}
	
	for(int mask=0;mask<1<<N;mask++) {
		vector<int> C(10,0);
		FOR(i,N) if(mask&(1<<i)) C[S[i]-'0']++;
		V.insert(C);
		if(mask+1==(1<<N)) ma=C;
	}
	
	ll ret=0;
	FORR(v,V) {
		vector<int> VV=v;
		int ng=0;;
		FOR(i,10) if((VV[i]==0)!=(ma[i]==0)) ng=1;
		if(ng==1) continue;
		
		for(i=1;i<10;i++) if(VV[i]) {
			VV[i]--;
			int sum=0;
			FORR(vv,VV) sum+=vv;
			ll pat=fact[sum];
			FORR(vv,VV) pat/=fact[vv];
			ret+=pat;
			VV[i]++;
			
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}