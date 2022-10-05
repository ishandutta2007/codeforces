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
string S,T;

int L[202020];
int R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	
	FOR(i,M+1) L[i]=303030,R[i]=-303030;
	int cur=0;
	FOR(i,N) if(cur<M&&S[i]==T[cur]) L[cur]=i, cur++;
	cur=M-1;
	for(i=N-1;i>=0;i--) if(cur>=0&&S[i]==T[cur])  R[cur]=i, cur--;
	
	int ma=0;
	FOR(i,M-1) if(L[i]<R[i+1]) ma=max(ma,R[i+1]-L[i]);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}