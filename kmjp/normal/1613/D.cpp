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


int T,N,A[505050];
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		map<ll,ll> F,E;
		F[0]=1;
		FOR(i,N) {
			scanf("%d",&x);
			ll a=F[x-1]+E[x-1];
			ll b=F[x]+F[x+1];
			ll c=E[x+1];
			(E[x-1]+=a)%=mo;
			(F[x+1]+=b)%=mo;
			(E[x+1]+=c)%=mo;
		}
		
		ll ret=-1;
		FORR2(a,b,F) ret+=b;
		FORR2(a,b,E) ret+=b;
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}