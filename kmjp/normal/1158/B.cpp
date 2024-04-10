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

int N,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	int step=0;
	FOR(i,N) {
		step++;
		if(step%((N-K+2)/2)==0) cout<<1;
		else cout<<0;
	}
	cout<<endl;
	
	/*
	if(N==K) {
		FOR(i,N) cout<<1;
		cout<<endl;
		return;
	}
	int mask=0;
	y=10;
	vector<string> C[33];
	FOR(mask,1<<y) {
		string S;
		map<string,int> V;
		FOR(i,y) S.push_back('0'+((mask>>i)&1));
		FOR(x,y) for(l=1;x+l<=y;l++) V[S.substr(x,l)]++;
		
		x=y;
		FORR(v,V) if(v.second==1) x=min(x,(int)v.first.size());
		C[x].push_back(S);
	}
	
	for(i=1;i<=y;i++) if(i%2==y%2) {
		cout<<i<<"--------------"<<endl;
		FORR(c,C[i]) cout<<" "<<c<<endl;
	}
	*/
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}