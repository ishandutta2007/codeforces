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

int N,X;
int M;
ll ma[1<<20];

int ret[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		ll C,D,H;
		cin>>C>>D>>H;
		ma[C]=max(ma[C],D*H);
	}
	
	for(i=X;i>=1;i--) {
		for(j=i;j<=X;j+=i) ma[j]=max(ma[j],ma[i]*(j/i));
	}
	for(i=2;i<=X;i++) ma[i]=max(ma[i],ma[i-1]);
	
	
	
	cin>>M;
	FOR(i,M) {
		ll D,H;
		cin>>D>>H;
		H*=D;
		if(ma[X]<=H) {
			cout<<-1<<" ";
		}
		else {
			x=lower_bound(ma,ma+X+1,H+1)-ma;
			cout<<x<<" ";
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}