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

int T;
int N;
ll C[202020];
ll A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>C[i];
		FOR(i,N) cin>>A[i];
		FOR(i,N) {
			cin>>B[i];
			C[i]--;
			A[i]--;
			B[i]--;
			if(B[i]<A[i]) swap(A[i],B[i]);
		}
		
		ll cur=B[1]-A[1]+2;
		ll ma=0;
		for(i=1;i<N;i++) {
			ma=max(ma,cur+C[i]);
			if(i<N&&A[i+1]!=B[i+1]) {
				cur=max(B[i+1]-A[i+1],cur+C[i]-(B[i+1]-A[i+1]))+2;
			}
			else {
				cur=2;
			}
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}