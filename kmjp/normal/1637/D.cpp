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

int T,N,A[101],B[101];

ll from[22001];
ll to[22001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		
		FOR(i,21001) from[i]=1LL<<60;
		from[0]=0;
		int s=0;
		FOR(i,N) {
			FOR(j,s+200+1) to[j]=1LL<<60;
			FOR(j,s+1) {
				int r=s-j;
				to[j+A[i]]=min(to[j+A[i]],from[j]+2*j*A[i]+2*r*B[i]);
				to[j+B[i]]=min(to[j+B[i]],from[j]+2*j*B[i]+2*r*A[i]);
			}
			swap(from,to);
			s+=A[i]+B[i];
		}
		ll ret=1LL<<60;
		FOR(i,s+1) ret=min(ret,from[i]);
		FOR(i,N) ret+=(N-1)*(A[i]*A[i]+B[i]*B[i]);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}