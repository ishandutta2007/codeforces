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
ll L[19][1<<18];
ll R[19][1<<18];
ll S[19][1<<18];
ll ma[19][1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,(1<<N)) {
		cin>>x;
		L[0][i]=max(0,x);
		R[0][i]=max(0,x);
		S[0][i]=x;
		ma[0][i]=max(0,x);
	}
	for(i=1;i<=N;i++) {
		FOR(j,1<<N) {
			x=j;
			y=j^(1<<(i-1));
			L[i][j]=max(L[i-1][x],S[i-1][x]+L[i-1][y]);
			R[i][j]=max(R[i-1][y],S[i-1][y]+R[i-1][x]);
			S[i][j]=S[i-1][x]+S[i-1][y];
			ma[i][j]=max({ma[i-1][x],ma[i-1][y],R[i-1][x]+L[i-1][y]});
		}
	}
	
	int cur=0;
	cin>>Q;
	while(Q--) {
		cin>>x;
		cur^=1<<x;
		cout<<ma[N][cur]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}