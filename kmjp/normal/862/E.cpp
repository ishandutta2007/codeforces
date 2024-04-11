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

int N,M,Q;
int A[101010],B[101010];
ll BS[101010];
vector<ll> cand;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&Q);
	ll sum=0;
	FOR(i,N) {
		scanf("%d",&A[i]);
		sum+=((i%2==0)?1:-1)*A[i];
	}
	FOR(i,M) scanf("%d",&B[i]);
	
	for(i=M-1;i>=0;i--) {
		BS[i]=B[i]-BS[i+1];
		if(i+N<=M) cand.push_back(BS[i]+((N%2==1)?BS[i+N]:-BS[i+N]));
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	while(1) {
		ll mi=1LL<<60;
		x=lower_bound(ALL(cand),sum)-cand.begin();
		for(i=max(0,x-2);i<min(x+3,(int)cand.size());i++) mi=min(mi,abs(sum-cand[i]));
		cout<<mi<<endl;
		
		if(Q==0) break;
		Q--;
		int L,R,X;
		scanf("%d%d%d",&L,&R,&X);
		if((R-L)%2==0) {
			if(L%2==0) sum-=X;
			else sum+=X;
		}
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}