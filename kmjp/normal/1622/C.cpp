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
ll K;
ll A[202020];
ll S[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		sort(A,A+N);
		FOR(i,N) {
			S[i+1]=S[i]+A[i];
		}
		if(S[N]<=K) {
			cout<<0<<endl;
			continue;
		}
		ll mi=1LL<<60;
		FOR(i,N) {
			ll lef=S[N-i]-S[1];
			if(lef+(i+1)*A[0]<=K) {
				mi=min(mi,(ll)i);
			}
			else {
				ll ma=K-lef;
				if(ma%(i+1)==0||ma>=0) {
					ma=ma/(i+1);
				}
				else {
					ma=ma/(i+1)-1;
				}
				mi=min(mi,i+A[0]-ma);
			}
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