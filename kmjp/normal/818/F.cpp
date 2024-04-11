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

int Q;
ll N;

ll ok(ll center,ll tot) {
	ll edge=tot-center;
	
	if(edge<center) return -1;
	return edge+min(edge,center*(center-1)/2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		ll ma=0;
		
		if(N<100) {
			for(i=1;i<=N;i++) ma=max(ma,ok(i,N));
		}
		else {
			ll L=1,R=N;
			
			while(R-L>10) {
				ll M1=(L*2+R)/3;
				ll M2=(L+R*2)/3;
				ll A1=ok(M1,N);
				ll A2=ok(M2,N);
				if(A1>=A2) R=M2;
				if(A1<=A2) L=M1;
			}
			for(i=L;i<=R;i++) ma=max(ma,ok(i,N));
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}