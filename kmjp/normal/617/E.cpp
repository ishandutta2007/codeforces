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

int N,M,K;
int A[101010];
int LL[101010],RR[101010];
int L[101010],R[101010];
ll ret[101010];

int NL[2020200];
int NR[2020200];

vector<pair<int,int>> ev[2000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>A[i];
		if(i) LL[i]=LL[i-1]^A[i-1];
		RR[i]=((i?RR[i-1]:0)^A[i]);
	}
	FOR(i,N) RR[i]^=K;
	
	FOR(i,M) {
		cin>>L[i]>>R[i];
		L[i]--;
		R[i]--;
		ev[L[i]/2000].push_back({R[i],i});
	}
	
	ll cn=0;
	int cl=0,cr=-1;
	FOR(i,2000) if(ev[i].size()) {
		sort(ALL(ev[i]));
		FORR(r,ev[i]) {
			int tl=L[r.second],tr=R[r.second];
			
			while(tl<cl) cl--, NR[RR[cl]]++, cn+=NR[LL[cl]], NL[LL[cl]]++;
			while(cr<tr) cr++, NL[LL[cr]]++, cn+=NL[RR[cr]], NR[RR[cr]]++;
			while(tl>cl) NL[LL[cl]]--, cn-=NR[LL[cl]], NR[RR[cl]]--, cl++;
			while(cr>tr) NR[RR[cr]]--, cn-=NL[RR[cr]], NL[LL[cr]]--, cr--;
			ret[r.second]=cn;
		}
	}
	
	
	FOR(i,M) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}