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

int N;
ll A[202020];

int M;
ll X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll S=0;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
	}
	sort(A,A+N);
	
	cin>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		x=lower_bound(A,A+N,X[i])-A;
		ll mi=1LL<<60;
		if(x<N) {
			ll a=S-A[x];
			mi=min(mi,max(Y[i]-a,0LL));
		}
		if(x>0) {
			x--;
			ll a=S-A[x];
			mi=min(mi,X[i]-A[x]+max(Y[i]-a,0LL));
		}
		
		
		cout<<mi<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}