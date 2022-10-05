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

int N;
int C[101];
int B[101],S[101];
int Q;
int X;
const ll mo=1000000007;
ll from[10101];
ll to[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll allpat=1;
	FOR(i,N) {
		cin>>C[i];
		allpat=allpat*(C[i]+1)%mo;
	}
	FOR(i,N-1) {
		cin>>x;
		B[i+1]=B[i]+x;
		S[i+1]=S[i]+B[i+1];
	}
	
	int lower=1LL<<30;
	for(i=1;i<=N;i++) {
		lower=min(lower,(100*i-S[i-1])/i-3);
	}
	
	
	map<int,ll> memo;
	for(X=lower-110;X<=lower+5;X++) {
		ZERO(from);
		from[0]=1;
		FOR(i,N) {
			ZERO(to);
			y=C[i];
			FOR(x,100*i+1) {
				
				int border=x-S[i]-X*(i+1);
				if(border>=0) {
					(to[x]+=from[x])%=mo;
					(to[x+y+1]+=mo-from[x])%=mo;
				}
				else if(border<-y) {
					;
				}
				else {
					(to[x-border]+=from[x])%=mo;
					(to[x+y+1]+=mo-from[x])%=mo;
				}
			}
			for(x=1;x<=100*(i+1)+1;x++) {
				(to[x]+=to[x-1])%=mo;
			}
			
			swap(from,to);
		}
		ll ret=0;
		FOR(i,10100) ret+=from[i];
		memo[X]=ret%mo;
	}
	
	cin>>Q;
	while(Q--) {
		cin>>X;
		if(X>lower+5) {
			cout<<0<<endl;
		}
		else if(X<lower-110) {
			cout<<allpat<<endl;
		}
		else {
			cout<<memo[X]<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}