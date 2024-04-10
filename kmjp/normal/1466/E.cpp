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
int N;
ll X[505050];
const ll mo=1000000007;
ll C[61];
ll p2[122];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,120) p2[i+1]=p2[i]*2%mo;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(C);
		FOR(i,N) {
			cin>>X[i];
			FOR(j,60) if(X[i]&(1LL<<j)) C[j]++;
		}
		ll ret=0;
		FOR(i,N) {
			ll pat=0;
			FOR(j,60) {
				if(X[i]&(1LL<<j)) (pat+=N*p2[j])%=mo;
				else (pat+=C[j]*p2[j])%=mo;
			}
			FOR(j,60) if(X[i]&(1LL<<j)) {
				(ret+=C[j]*pat%mo*p2[j])%=mo;
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