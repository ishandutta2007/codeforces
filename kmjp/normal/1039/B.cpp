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

bool ask(ll L,ll R) {
	string S;
	cout<<L<<" "<<R<<endl;
	cout.flush();
	cin>>S;
	if(S=="Yes") {
		if(L==R) exit(0);
		return true;
	}
	assert(S=="No");
	return false;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll L=1;
	ll R=N;
	srand(time(NULL));
	while(1) {
		while(R-L>=45) {
			ll M=(R+L)/2;
			if(ask(L,M)) R=M;
			else L=M+1;
			R=min(R+K,N);
			L=max(L-K,1LL);
		}
		
		ll v=rand()%(R-L+1);
		ask(L+v,L+v);
		
		R=min(R+K,N);
		L=max(L-K,1LL);
		
	}
	
}


int main(int argc,char** argv){
	solve(); return 0;
}