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
int A[2][202020];
int B[2][202020];
int C[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[0][i];
	FOR(i,N) cin>>A[1][i];
	FOR(i,N) cin>>B[0][i];
	FOR(i,N) cin>>B[1][i];
	int U=0,D=0;
	ll sum=0;
	FOR(i,N) {
		U+=A[0][i]-B[0][i];
		D+=A[1][i]-B[1][i];
		x=min(abs(U),abs(D));
		if(U>0&&D<0) {
			sum+=x;
			U-=x;
			D+=x;
		}
		if(U<0&&D>0) {
			sum+=x;
			U+=x;
			D-=x;
		}
		sum+=abs(U)+abs(D);
	}
	if(U||D) {
		cout<<-1<<endl;
	}
	else {
		cout<<sum<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}