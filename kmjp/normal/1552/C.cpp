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

int T,N,K;
int X[201],Y[202];
int valid[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,2*N) valid[i]=1;
		int ret=0;
		FOR(i,K) {
			cin>>X[i]>>Y[i];
			X[i]--;
			Y[i]--;
			if(X[i]>Y[i]) swap(X[i],Y[i]);
			valid[X[i]]=0;
			valid[Y[i]]=0;
		}
		vector<int> E;
		FOR(i,2*N) if(valid[i]==1) E.push_back(i);
		FOR(i,E.size()/2) {
			X[K+i]=E[i];
			Y[K+i]=E[i+E.size()/2];
		}
		K+=E.size()/2;
		FOR(y,K) FOR(x,K) {
			if(X[x]<X[y]&&X[y]<Y[x]&&Y[x]<Y[y]) ret++;
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