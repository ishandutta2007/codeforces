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
int X[202020],Y[202020],S[202020];
ll dp[202020];
ll dpS[202020];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> Xs;
	Xs.push_back(0);
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>S[i];
		Xs.push_back(X[i]);
		Xs.push_back(Y[i]);
	}
	Xs.push_back(X[N-1]+1);
	sort(ALL(Xs));
	FOR(i,N) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		Y[i]=lower_bound(ALL(Xs),Y[i])-Xs.begin();
	}

	ll ret=Xs.back();
	FOR(i,N) {
		dp[i]=Xs[X[i]]-Xs[Y[i]];
		x=lower_bound(X,X+N,Y[i])-X;
		(dp[i]+=mo+dpS[i]-dpS[x])%=mo;
		(dpS[i+1]=dpS[i]+dp[i])%=mo;
		if(S[i]) ret+=dp[i];
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}