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
int N,M;
int A[202020],X;
ll S[202020],ma[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i]+A[i];
			ma[i+1]=max(ma[i],S[i+1]);
		}
		while(M--) {
			cin>>X;
			ll ret=0;
			if(X>ma[N]) {
				if(S[N]<=0) {
					cout<<-1<<" ";
					continue;
				}
				ll del=X-ma[N];
				ll loop=(del+S[N]-1)/S[N];
				ret+=loop*N;
				X-=loop*S[N];
			}
			
			x=N;
			for(i=20;i>=0;i--) while(x>(1<<i)&&ma[x-(1<<i)]>=X) x-=1<<i;
			cout<<(ret+x-1)<<" ";
			
			
		}
		cout<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}