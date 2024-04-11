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
ll A[101010];
ll S[101010];
ll from[101010];
ll to[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i]+A[i];
		}
		int k=1;
		from[N]=0;
		for(i=N-1;i>=0;i--) from[i]=max(A[i],from[i+1]);
		while(1) {
			int ok=0;
			for(i=N-1;i>=0;i--) {
				if(i+k+1>=N) {
					to[i]=-1LL<<60;
				}
				else {
					if(S[i+k+1]-S[i]<from[i+k+1]) {
						to[i]=S[i+k+1]-S[i];
						ok=1;
					}
					else {
						to[i]=-1LL<<60;
					}
				}
			}
			
			if(ok==0) break;
			from[N]=to[N]=-1LL<<60;
			for(i=N-1;i>=0;i--) from[i]=max(to[i],from[i+1]);
			k++;
		}
		cout<<k<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}