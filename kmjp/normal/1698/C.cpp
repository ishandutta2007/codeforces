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
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		sort(A,A+N);
		
		if(N<=6) {
			int ok=1;
			FOR(k,N) FOR(y,k) FOR(x,y) {
				ll s=A[x]+A[y]+A[k];
				if(count(A,A+N,s)==0) ok=0;
			}
			if(ok) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
		else {
			ll p=0,m=0;
			FOR(i,N) {
				if(A[i]>0) {
					if(p) p=1LL<<40;
					else p=A[i];
				}
				if(A[i]<0) {
					if(m) m=-(1LL<<41);
					else m=A[i];
				}
			}
			
			if(p>=1LL<<40||m<=-(1LL<<41)) {
				cout<<"No"<<endl;
			}
			else if(p&&m&&p!=-m) {
				cout<<"No"<<endl;
			}
			else {
				cout<<"Yes"<<endl;
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