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
ll A[2020202];
vector<ll> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	N=unique(A,A+N)-A;
	
	ll cur=0;
	for(i=1;i<=4020200;i++) {
		V.push_back(cur);
		cur+=i;
		V.push_back(cur);
		cur+=i-1;
	}
	
	for(i=2;i<=4020200;i+=2) {
		ll lo=max(0LL,V[i]-A[0]);
		ll hi=V[i+1]-1-A[0];
		ll add=lo;
		for(j=i;j<=4020200&&lo<=hi;j++) {
			if(V[j]-V[i]>15505000) break;
			x=lower_bound(A,A+N,V[j]-add)-A;
			y=lower_bound(A+x,A+N,V[j+1]-add)-A;
			if(x<y) {
				if(j%2==0) {
					hi=min(hi,V[j+1]-A[y-1]-1);
				}
				else {
					lo=max(lo,V[j+1]-A[x]);
				}
			}
		}
		if(lo<=hi) {
			cout<<lo<<endl;
			return;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}