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

int N,K;
int C[505050];
int A[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	scanf("%d%d",&N,&K);
	FOR(i,N) scanf("%d",&C[i]);
	
	ll tot=0;
	sort(C,C+N);
	FOR(i,N) tot+=C[i];
	FOR(i,N) A[N-1-i]=tot/N + (i<(tot%N));
	
	ll di=0;
	FOR(i,N) if(C[i]>A[i]) di+=C[i]-A[i];
	K=min((ll)K,di);
	
	int L=K;
	i=N-1;
	while(L>=0) {
		ll h=C[i]-C[i-1];
		if(L>h*(N-i)) {
			L-=h*(N-i);
			i--;
			continue;
		}
		FOR(j,N-i) C[N-1-j] = C[i]- (L/(N-i) + (j<(L%(N-i))));
		break;
	}
	sort(C,C+N);
	L=K;
	i=0;
	while(L>=0) {
		ll h=C[i+1]-C[i];
		if(L>h*(i+1)) {
			L-=h*(i+1);
			i++;
			continue;
		}
		FOR(j,i+1) C[j] = C[i] + L/(i+1) + (j<(L%(i+1)));
		break;
	}
	sort(C,C+N);
	cout<<C[N-1]-C[0]<<endl;
	
}


int main(int argc,char** argv){
	solve(); return 0;
}