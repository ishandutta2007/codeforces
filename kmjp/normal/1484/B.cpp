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

int T,N,A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		
		x=y=-1<<30;
		FOR(i,N-1) {
			if(A[i]<A[i+1]) {
				if(x!=-1<<30&&A[i+1]-A[i]!=x) break;
				x=A[i+1]-A[i];
			}
			else {
				if(y!=-1<<30&&A[i+1]-A[i]!=y) break;
				y=A[i+1]-A[i];
			}
		}
		
		if(i<N-1) {
			cout<<-1<<endl;
		}
		else if(y==-1<<30||x==-1<<30) {
			cout<<0<<endl;
		}
		else {
			int M=x-y;
			int C=x;
			FOR(i,N-1) if(A[i+1]!=(A[i]+C)%M) break;
			if(i<N-1 || A[0]>=M) {
				cout<<-1<<endl;
			}
			else {
				cout<<M<<" "<<C<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}