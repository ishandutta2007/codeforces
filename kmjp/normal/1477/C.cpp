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
ll X[5050],Y[5050];
int P[5050];
int vis[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int mi=0;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		if(X[i]<X[mi]) mi=i;
		if(X[i]==X[mi]&&Y[i]<Y[mi]) mi=i;
	}
	
	P[0]=mi;
	vis[mi]=1;
	FOR(i,N-1) {
		int cur=P[i];
		ll r=0;
		int tar=0;
		FOR(j,N) if(vis[j]==0) {
			ll v=(X[cur]-X[j])*(X[cur]-X[j])+(Y[cur]-Y[j])*(Y[cur]-Y[j]);
			if(v>r) r=v,tar=j;
		}
		P[i+1]=tar;
		vis[tar]=1;
	}
	
	FOR(i,N) cout<<P[i]+1<<" ";
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}