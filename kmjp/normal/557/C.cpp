#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int ND[202];
int L[101010],D[101010];
vector<int> DL[101010];
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	FOR(i,N) {
		cin>>D[i];
		ND[D[i]]++;
		DL[L[i]].push_back(D[i]);
	}
	
	ll mi=1LL<<30;
	ll tot=0;
	int left=N;
	
	for(i=101000;i>=0;i--) if(DL[i].size()) {
		
		int rem=max(0,left - (int)(DL[i].size()*2-1));
		FORR(r,DL[i]) ND[r]--;
		ll tot2=0;
		for(j=1;j<=200 && rem;j++) {
			x=min(rem,ND[j]);
			tot2 += x*j;
			rem-=x;
		}
		mi=min(mi,tot+tot2);
		
		FORR(r,DL[i]) tot+=r;
		left -= DL[i].size();
	}
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}