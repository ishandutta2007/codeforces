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

int N,M;
int L[55],R[55];
ll from[1010101];
ll to[1010101];
ll gcdp[101010];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>L[i]>>R[i];
	
	for(x=M;x>=1;x--) {
		int ma=M/x;
		FOR(y,ma+2) from[y]=0;
		from[0]=1;
		FOR(i,N) {
			FOR(y,ma+2) to[y]=0;
			int l=(L[i]+x-1)/x;
			int r=R[i]/x;
			if(l>r) break;
			FOR(y,ma+1) {
				(to[min(ma+1,y+l)]+=from[y])%=mo;
				(to[min(ma+1,y+r+1)]+=mo-from[y])%=mo;
			}
			FOR(y,ma+2) (to[y+1]+=to[y])%=mo;
			FOR(y,ma+2) from[y]=to[y];
		}
		if(i<N) continue;
		FOR(y,ma+1) (gcdp[x]+=from[y])%=mo;
		for(j=x*2;j<=M;j+=x) gcdp[x]+=mo-gcdp[j];
		gcdp[x]%=mo;
		
	}
	cout<<gcdp[1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}