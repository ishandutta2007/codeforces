#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,D,K;
int nex;
vector<pair<int,int>> V;

void dfs(int cur,int cand,int left) {
	if(cur>N || left==0) return;
	int i;
	FOR(i,cand) {
		if(nex>N) return;
		int tn=nex++;
		V.push_back({cur,tn});
		dfs(tn,K-1,left-1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>K;
	if(N==2 && D==1) {
		cout<<"YES"<<endl;
		cout<<"1 2"<<endl;
		return;
	}
	if(N==1 || D==1 || K==1) {
		cout<<"NO"<<endl;
		return;
	}
	if(N<D+1) {
		cout<<"NO"<<endl;
		return;
	}
	
	FOR(i,D) V.push_back({i+1,i+2});
	nex=D+2;
	for(i=1;i<=D+1;i++) dfs(i,K-2,D-max(i-1,D+1-i));
	if(nex<=N) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}