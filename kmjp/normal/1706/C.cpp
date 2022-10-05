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

int T,N,H[303030];
ll sum[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>H[i];
		
		ll ret;
		if(N%2==1) {
			ret=0;
			for(i=1;i<N;i+=2) {
				if(H[i]<=max(H[i-1],H[i+1])) ret+=max(H[i-1],H[i+1])+1-H[i];
			}
		}
		else {
			ret=1LL<<60;
			for(i=1;i<N;i+=2) {
				sum[i]=0;
				if(i>=2) sum[i]=sum[i-2];
				if(H[i]<=max(H[i-1],H[i+1])) sum[i]+=max(H[i-1],H[i+1])+1-H[i];
			}
			ret=sum[N-3];
			ll a=0;
			for(i=N-2;i>=1;i-=2) {
				if(H[i]<=max(H[i-1],H[i+1])) a+=max(H[i-1],H[i+1])+1-H[i];
				ret=min(ret,a+((i>=3)?sum[i-3]:0));
			}
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}