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

int N,T;
set<pair<int,int>> S;
int A[202020];

int ask(int N) {
	int r;
	if(A[N]>=0) return A[N];
	cout<<"? 1 "<<N<<endl;
	cin>>r;
	return A[N]=N-r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	MINUS(A);
	A[0]=0;
	
	while(T--) {
		cin>>x;
		ask(N);
		
		int R=N;
		int L=0;
		while(L+1<R) {
			int M=(L+R)/2;
			if(ask(M)>=x) R=M;
			else L=M;
		}
		cout<<"! "<<R<<endl;
		for(i=R;i<=N;i++) A[i]--;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}