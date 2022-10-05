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


int T,N,A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		sort(A,A+N);
		
		if(N%2) {
			cout<<"NO"<<endl;
		}
		else {
			FOR(i,N/2) {
				B[2*i]=A[i];
				B[2*i+1]=A[N/2+i];
			}
			
			FOR(i,N) {
				int L=(i?B[i-1]:B[N-1]);
				int R=(i<N-1?B[i+1]:B[0]);
				
				if(L<B[i]&&B[i]>R) continue;
				if(L>B[i]&&B[i]<R) continue;
				break;
			}
			if(i<N) {
				cout<<"NO"<<endl;
			}
			else {
				cout<<"YES"<<endl;
				FOR(i,N) cout<<B[i]<<" ";
				cout<<endl;
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