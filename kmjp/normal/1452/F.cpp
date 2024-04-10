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

int N,Q;
ll C[35];
ll X,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>C[i];
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			C[x]=y;
		}
		else {
			cin>>X>>K;
			
			ll ret=0;
			ll small=0;
			FOR(i,X+1) {
				small+=((1LL<<i)-1)*C[i];
				K-=C[i];
			}
			
			if(K<=0) {
				cout<<0<<endl;
				continue;
			}
			
			
			
			for(i=X+1;i<N;i++) {
				ll p=1LL<<(i-X);
				ll num=min(K/p,C[i]);
				ret+=num*(p-1);
				small+=num*p*((1LL<<X)-1);
				K-=num*p;
				if(num<C[i]) break;
			}
			
			if(K<=0) {
				cout<<ret<<endl;
				continue;
			}
			
			if(i==N) {
				if(K>small) cout<<-1<<endl;
				else cout<<(ret+K)<<endl;
				continue;
			}
			
			ll mi=1LL<<60;
			for(;i>=X+1;) {
				if(small>=K) mi=min(mi,ret+K);
				ret++;
				i--;
				if(1LL<<(i-X)<=K) {
					ret+=(1LL<<(i-X))-1;
					K-=1LL<<(i-X);
					small+=(1LL<<(i-X))*((1LL<<X)-1);
				}
			}
			cout<<min(mi,ret)<<endl;
			
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}