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

int N[3];
ll A[3][303030];
ll S[3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>N[i];
	FOR(i,3) {
		FOR(j,N[i]) {
			cin>>A[i][j];
			S[i]+=A[i][j];
		}
		sort(A[i],A[i]+N[i]);
	}
	ll ret=-1LL<<60;
	ret=max(ret,S[0]+S[1]-S[2]);
	ret=max(ret,S[0]+S[2]-S[1]);
	ret=max(ret,S[1]+S[2]-S[0]);
	ret=max(ret,S[0]+S[1]+S[2]-2*(A[0][0]+A[1][0]));
	ret=max(ret,S[0]+S[1]+S[2]-2*(A[0][0]+A[2][0]));
	ret=max(ret,S[0]+S[1]+S[2]-2*(A[1][0]+A[2][0]));
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}