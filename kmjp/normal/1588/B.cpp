#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;

ll ask(int L,int R) {
	if(R<=L) return 0;
	cout<<"? "<<L<<" "<<R<<endl;
	ll a;
	cin>>a;
	return a;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		
		cin>>N;
		ll tot=ask(1,N);
		for(i=30;i>=0;i--) {
			ll a=ask(1,N-(1<<i));
			if(tot==a) N-=1<<i;
		}
		ll tot2=ask(1,N-1);
		int R=N;
		int M=N-(tot-tot2)-1;
		
		ll a=ask(1,M);
		ll b=ask(1,M-1);
		int L=M-(a-b);
		cout<<"! "<<L<<" "<<(M+1)<<" "<<R<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}